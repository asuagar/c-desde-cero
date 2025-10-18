 /*
 * 25_simple_text_editor.c - Parte 3, Proyecto final: Editor de texto simple
 *
 * Este proyecto final construye un editor de texto funcional basado en líneas.
 * Integra muchos conceptos del curso: listas doblemente enlazadas, memoria
 * dinámica, E/S de archivos, argumentos de línea de comandos y manipulación
 * de cadenas.
 *
 * Fecha: 15-06-2025
 * Autores:
 *   DunamisMax <github.com/dunamismax>
 *   Andrés Suárez <github.com/asuagar>
 *
 * SPDX-License-Identifier: MIT
 */

/*
 * ====================================================================
 *                           - INICIO DE LA LECCIÓN -             
 * ====================================================================
 *
 * ¡Bienvenido al proyecto final de la Parte 3!
 * Aquí reunimos todo lo aprendido para construir una aplicación real:
 * un editor de texto por línea, al que llamaremos `sled`
 * (Simple Line Editor).
 *
 * Nuestro editor podrá abrir un archivo, mostrar su contenido,
 * añadir o eliminar líneas y guardar los cambios.
 *
 * ESTRUCTURA DE DATOS CENTRAL:
 * 
 * El corazón del editor es una LISTA DOBLEMENTE ENLAZADA. En estas listas,
 * Cada nodo apunta tanto al siguiente como al anterior,
 * lo que facilita insertar o borrar líneas en medio del texto.
 *
 * En nuestro programa, cada nodo representa una línea del archivo.
 *
 * HABILIDADES INTEGRADAS:
 * 
 * - Estructuras (`struct`) para definir nodos.
 * - Punteros (`next`, `prev`) para conectar líneas.
 * - Memoria dinámica (`malloc`/`free`) para gestionar nodos.
 * - E/S de archivos (`fopen`, `fgets`, `fprintf`) para cargar y guardar.
 * - Argumentos de línea de comandos (`argc`, `argv`).
 * - Funciones modulares y legibles.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> /* Para el uso del flag booleano `modified` */


/* --- Estructuras de datos y estado global --- 
 * El nodo de la lista doblemente enlazada. 
 * Cada nodo es una línea de texto.
 */
typedef struct Line {
    char *text;        /* Texto de la línea (memoria dinámica) */
    struct Line *prev; /* Puntero a la línea anterior */
    struct Line *next; /* Puntero a la línea siguiente */
} Line;

/* Punteros globales al inicio y final del buffer de texto */
Line *head = NULL;
Line *tail = NULL;
int line_count = 0;
bool modified = false; /* Indica si hubo cambios sin guardar */

/* --- Prototipos de funciones --- */
void load_file(const char *filename);
void save_file(const char *filename);
void free_buffer(void);
void print_lines(void);
void insert_line(int line_number, const char *text);
void delete_line(int line_number);
void append_line(const char *text);
void print_help(void);

/* --- Función principal: bucle de control del editor --- */
int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <nombre_archivo>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    load_file(filename);

    char input_buffer[1024];
    printf("Simple Line Editor. Escribe 'h' para ayuda, 'q' para salir.\n");

    while (true) {
        printf("> ");
        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL)
            break; /* Salir con Ctrl+D */

        /* procesar comandos y argumentos */
        char command = input_buffer[0];
        char *argument = input_buffer + 2;
        int line_num = atoi(argument);

        switch (command) {
        case 'p':
            print_lines();
            break;
        case 'a': 
            /* remover nueva línea de un argumento */
            argument[strcspn(argument, "\n")] = 0;
            append_line(argument);
            break;
        case 'i': {
            /* quitar número línea del texto */
            char *text_start = strchr(argument, ' ');
            if (text_start) {
                *text_start = '\0';
                text_start++;
                text_start[strcspn(text_start, "\n")] = 0;
                insert_line(atoi(argument), text_start);
            } else {
                printf("Uso: i <número_línea> <texto>\n");
            }
            break;
        }
        case 'd': //  borrar //
            delete_line(line_num);
            break;
        case 's':
            save_file(filename);
            break;
        case 'h':
            print_help();
            break;
        case 'q':
            if (modified) {
                printf("Hay cambios sin guardar. ¿Deseas guardar? (y/n): ");
                if (fgets(input_buffer, sizeof(input_buffer), stdin) != NULL &&
                    (input_buffer[0] == 'y' || input_buffer[0] == 'Y'))
                    save_file(filename);
            }
            printf("Saliendo.\n");
            free_buffer();
            return 0;
        default:
            printf("Comando desconocido. Escribe 'h' para ayuda.\n");
        }
    }

    free_buffer();
    return 0;
}

/* --- Implementaciones de funciones --- */

/* Imprime el menú de ayuda. */
void print_help(void)
{
    printf("--- Ayuda de sled ---\n");
    printf("p              - Mostrar todas las líneas\n");
    printf("a <texto>      - Añadir una nueva línea al final\n");
    printf("i <n> <texto>  - Insertar antes de la línea <n>\n");
    printf("d <n>          - Borrar la línea <n>\n");
    printf("s              - Guardar el archivo\n");
    printf("h              - Mostrar este mensaje de ayuda\n");
    printf("q              - Salir del editor\n");
}

/* Reserva espacio para una nueva línea. */
Line *create_line(const char *text)
{
    Line *new_line = (Line *)malloc(sizeof(Line));
    if (!new_line) {
        perror("malloc falló para la línea");
        exit(1);
    }

    new_line->text = malloc(strlen(text) + 1);
    if (!new_line->text) {
        perror("malloc falló para el texto");
        exit(1);
    }

    strcpy(new_line->text, text);
    new_line->prev = NULL;
    new_line->next = NULL;
    return new_line;
}

/* Añade una nueva línea al final del buffer. */
void append_line(const char *text)
{
    Line *new_line = create_line(text);
    if (tail == NULL)
        head = tail = new_line;
    else {
        tail->next = new_line;
        new_line->prev = tail;
        tail = new_line;
    }
    line_count++;
    modified = true;
}

/* Carga el contenido del fichero en una nueva lista. */
void load_file(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Nuevo archivo: '%s'\n", filename);
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = 0;
        append_line(buffer);
    }
    fclose(file);
    modified = false;
}

/* Salva el contenido del buffer a un fichero. */
void save_file(const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("No se pudo abrir el archivo para escritura");
        return;
    }

    Line *current = head;
    while (current != NULL) {
        fprintf(file, "%s\n", current->text);
        current = current->next;
    }
    fclose(file);
    printf("Archivo '%s' guardado.\n", filename);
    modified = false;
}

/* Libera la memoria usada por el buffer. */
void free_buffer(void)
{
    Line *current = head;
    while (current != NULL) {
        Line *next = current->next;
        free(current->text);
        free(current);
        current = next;
    }
    head = tail = NULL;
    line_count = 0;
}

/* Imprime todas las líneas con su número. */
void print_lines(void)
{
    Line *current = head;
    int i = 1;
    while (current != NULL) {
        printf("%4d: %s\n", i++, current->text);
        current = current->next;
    }
}

/* Inserta una línea en una posición específica. */
void insert_line(int line_number, const char *text)
{
    if (line_number < 1 || line_number > line_count + 1) {
        printf("Error: número de línea inválido.\n");
        return;
    }

    if (line_number == line_count + 1) {
        append_line(text);
        return;
    }

    Line *new_line = create_line(text);
    Line *current = head;
    for (int i = 1; i < line_number; i++)
        current = current->next;

    new_line->next = current;
    new_line->prev = current->prev;

    if (current->prev == NULL)
        head = new_line;
    else
        current->prev->next = new_line;

    current->prev = new_line;
    line_count++;
    modified = true;
}

/* Borra la línea de una posición específica. */
void delete_line(int line_number)
{
    if (line_number < 1 || line_number > line_count) {
        printf("Error: número de línea inválido.\n");
        return;
    }

    Line *to_delete = head;
    for (int i = 1; i < line_number; i++)
        to_delete = to_delete->next;

    if (to_delete->prev)
        to_delete->prev->next = to_delete->next;
    else
        head = to_delete->next;

    if (to_delete->next)
        to_delete->next->prev = to_delete->prev;
    else
        tail = to_delete->prev;

    free(to_delete->text);
    free(to_delete);
    line_count--;
    modified = true;
}

/*
 * ====================================================================
 *                          - FIN DE LA LECCIÓN -               
 * ====================================================================
 *
 * ¡Felicidades! Has creado una aplicación funcional desde cero.
 * Este proyecto pone en práctica la gestión de memoria, punteros
 * y estructuras de datos complejas, además de modularidad y E/S.
 *
 * LOGROS CLAVE:
 * - Implementación de una lista doblemente enlazada.
 * - E/S de archivos robusta.
 * - Interfaz de línea de comandos simple.
 * - Gestión dinámica de memoria sin fugas.
 * - Código modular y claro.
 *
 * CÓMO COMPILAR Y EJECUTAR:
 *
 * 1) gcc -Wall -Wextra -std=c11 -o editor 25_simple_editor_texto.c
 * 2) ./editor mi_texto.txt
 *
 * Comandos sugeridos:
 * > a Primera línea
 * > a Segunda línea
 * > p
 * > i 2 Línea en medio
 * > p
 * > d 1
 * > s
 * > q
 */
