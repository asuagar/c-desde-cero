/*
 * 17_registro_estudiantes.c - Parte 3, Proyecto 17: Sistema de alumnos
 *
 * Este proyecto construye una aplicación con menú para gestionar registros
 * de alumnos. Demuestra cómo combinar structs, arrays, funciones y E/S de
 * ficheros para crear una herramienta con datos persistentes.
 *
 * Fecha: 15-06-2025
 * Autores:
 *   DunamisMax <github.com/dunamismax>
 *   Andrés Suárez <github.com/asuagar>
 *
 * SPDX-License-Identifier: MIT
 */

/*
 * =============================================================================
 *                           - INICIO DE LA LECCIÓN -
 * =============================================================================
 *
 * Aquí es donde todo se une. Construiremos una aplicación completa que:
 * 1. Añade nuevos registros de alumnos.
 * 2. Muestra todos los registros existentes.
 * 3. Guarda los registros en un fichero para no perder datos al cerrar.
 * 4. Carga los registros del fichero al iniciar el programa.
 *
 * Este patrón es la base de muchas aplicaciones de gestión de datos.
 *
 * CONCEPTOS DE ARQUITECTURA CLAVE:
 * - MODULARIDAD: dividimos el programa en funciones pequeñas y específicas
 *   (por ej., `add_student`, `save_to_file`). Facilita lectura, depuración
 *   y mantenimiento. `main` actúa como centro de control.
 * - PERSISTENCIA: con E/S de ficheros, los datos persisten entre ejecuciones.
 * - INTERFAZ DE USUARIO: se usa un menú de texto sencillo.
 * - GESTIÓN DE ERRORES: el programa maneja con cuidado errores de fichero
 *   y entradas inválidas del usuario.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* --- Constantes globales y tipos --- */
#define MAX_STUDENTS 100
#define MAX_NAME_LEN 50
#define FILENAME "students.db"

/* Estructura principal para un alumno. */
typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    double gpa;
} Student;

/* --- Prototipos --- */
/*
 * Declaramos las funciones para tener una vista general y poder llamarlas
 * desde `main` antes de su definición.
 */
void display_menu(void);
void add_student(Student students[], int *count);
void print_all_records(const Student students[], int count);
void save_to_file(const Student students[], int count);
void load_from_file(Student students[], int *count);
void clear_input_buffer(void);

/* --- Función principal: centro de control --- */
int main(void) 
{
    Student all_students[MAX_STUDENTS];
    int student_count = 0;
    int choice = 0;

    /* Cargar registros existentes del fichero de base de datos. */
    load_from_file(all_students, &student_count);

    /* Bucle principal de la aplicación. Termina cuando el usuario salga. */
    while (1) {
        display_menu();

        /* Leer la opción del menú. */
        if (scanf("%d", &choice) != 1) {
            /* Si la entrada no es un número, manejar el error. */
            printf("Invalid input. Please enter a number.\n");
            clear_input_buffer();
            continue;    /* Saltar resto del bucle y volver a empezar. */
        }
        clear_input_buffer();    /* Limpiar salto de línea pendiente. */

        switch (choice) {
        case 1:
            add_student(all_students, &student_count);
            break;
        case 2:
            print_all_records(all_students, student_count);
            break;
        case 3:
            save_to_file(all_students, student_count);
            break;
        case 4:
            printf("Exiting program. Goodbye!\n");
            exit(0);    /* exit(0): finaliza con éxito. */
        default:
            printf("Invalid choice. Please try again.\n");
        }

        printf("\n");    /* Espacio de lectura antes del siguiente menú. */
    }

    /* Esta línea es técnicamente inalcanzable, pero es 
     * buena práctica escribirla. 
     */
    return 0;
}

/* --- Implementaciones --- */

/*
 * Muestra el menú principal al usuario.
 */
void display_menu(void) 
{
    printf("--- Student Record System ---\n");
    printf("1. Add Student\n");
    printf("2. Display All Records\n");
    printf("3. Save Records to File\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

/*
 * Limpia el búfer de entrada estándar para evitar problemas con scanf.
 */
void clear_input_buffer(void) 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* Consumir caracteres hasta nueva línea o EOF. */
    }
}

/*
 * Añade un nuevo registro de alumno al array.
 * param students: el vector de los registros de estudiantes
 * param count: puntuero al actual número de estudiante. El puntero
 *              permite modificar la variable original `student_count`
 */
void add_student(Student students[], int *count) 
{
    if (*count >= MAX_STUDENTS) {
        printf("Database is full. Cannot add more students.\n");
        return;
    }

    printf("Enter Student ID: ");
    scanf("%d", &students[*count].id);
    clear_input_buffer();

    printf("Enter Student Name: ");
    /*
     * Leer una línea completa (incluye espacios) hasta el límite de tamaño.
     * `fgets` incluye el salto de línea; lo eliminamos.
     */
    fgets(students[*count].name, MAX_NAME_LEN, stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = 0;

    printf("Enter Student GPA: ");
    scanf("%lf", &students[*count].gpa);
    clear_input_buffer();

    printf("Student added successfully.\n");
    (*count)++;    /* Incrementar el número total de alumnos. */
}

/*
 * Imprime todos los registros en una tabla formateada.
 * param students: vector de estudiantes
 * param count: el número de estudiantes
 *              `const` indica que no se modifican los datos.
 */
void print_all_records(const Student students[], int count) 
{
    if (count == 0) {
        printf("No records to display.\n");
        return;
    }

    printf("\n--- All Student Records ---\n");
    printf("ID   | Name                                               | GPA\n");
    printf("-----|----------------------------------------------------|-----\n");
    for (int i = 0; i < count; i++) {
        /*
         * %-4d  : entero alineado a la izquierda en 4 espacios
         * %-50s : cadena alineada a la izquierda en 50 espacios
         * %5.2f : double alineado a la derecha en 5 espacios con 2 decimales
         */
        printf("%-4d | %-50s | %5.2f\n",
               students[i].id, students[i].name, students[i].gpa);
    }
    printf("----------------------------------------------------------------\n");
}

/*
 * Guarda todo el array de alumnos en un fichero.
 */
void save_to_file(const Student students[], int count) 
{
    /*
     * "w" para escribir; sobrescribe si existe.
     */
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        fprintf(stderr,
                "Error: Could not open file '%s' for writing.\n",
                FILENAME);
        return;
    }

    for (int i = 0; i < count; i++) {
        /*
         * Guardamos en formato CSV (valores separados por coma).
         * Es un formato sencillo y común.
         */
        fprintf(file, "%d,%s,%.2f\n",
                students[i].id, students[i].name, students[i].gpa);
    }

    fclose(file);
    printf("Successfully saved %d record(s) to %s.\n", count, FILENAME);
}

/*
 * Carga registros de alumnos desde un fichero al array.
 */
void load_from_file(Student students[], int *count) 
{
    /* "r" para lectura. */
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        /*
         * Si es la primera ejecución, no es un error que no exista.
         */
        printf("No existing database file found. Starting fresh.\n");
        return;
    }

    /*
     * `fscanf` devuelve el número de elementos leídos con éxito (esperamos 3).
     * El especificador `[^,]` lee hasta la coma. Limitamos a 49 chars.
     */
    while (*count < MAX_STUDENTS &&
           fscanf(file, "%d,%49[^,],%lf\n",
                  &students[*count].id,
                  students[*count].name,
                  &students[*count].gpa) == 3) {
        (*count)++;
    }

    fclose(file);
    printf("Successfully loaded %d record(s) from %s.\n",
           *count, FILENAME);
}

/*
 * =============================================================================
 *                            - FIN DE LA LECCIÓN -
 * =============================================================================
 *
 * ¡Enhorabuena! Has construido una aplicación completa de base de datos.
 * Este proyecto es un hito: demuestra un dominio sólido de las funciones
 * clave de C para software práctico.
 *
 * Logros del proyecto:
 * 
 * - Diseño modular con funciones por característica.
 * - Almacenamiento persistente en un fichero CSV sencillo.
 * - Menú interactivo limpio para controlar el programa.
 * - Gestión robusta de entrada del usuario y operaciones de sistema de ficheros.
 *
 * CÓMO COMPILAR Y EJECUTAR:
 * 
 * 1) Abre una terminal.
 * 2) Ve al directorio del fichero.
 * 3) Compila:
 *    gcc -Wall -Wextra -std=c11 -o registro 17_registro_estudiantes.c
 * 4) Ejecuta:
 *    Linux/macOS: ./registro
 *    Windows:     registro.exe
 *
 * Prueba a añadir alumnos, guardar, salir y volver a ejecutar.
 * Verás cómo los registros se cargan automáticamente.
 */
