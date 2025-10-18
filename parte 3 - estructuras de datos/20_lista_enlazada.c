/*
 * 20_lista_enlazada.c - Parte 3, Lista enlazada
 *
 * Este archivo es una lección y demostración para una
 * lista enlazada simple (singly linked list). Muestra cómo construir desde
 * cero una de las estructuras de datos dinámicas más fundamentales usando
 * estructuras (`structs`), punteros y asignación dinámica de memoria.
 * 
 * Fecha: 15-10-2025
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
 * Hasta ahora, nuestra principal forma de almacenar una colección de ítems
 * ha sido el ARREGLO (ARRAY). Los arreglos son geniales, pero tienen una
 * limitación importante: tienen un tamaño fijo. Si declaras 
 * `int my_array[100];`, no puedes almacenar 101 ítems sin crear un arreglo
 * nuevo y más grande y copiar todo.
 *
 * Bienvenido a la LISTA ENLAZADA, una estructura de datos que resuelve
 * este problema.
 *
 * ¿QUÉ ES UNA LISTA ENLAZADA?
 * 
 * Una LISTA ENLAZADA es una secuencia de elementos de datos, conectados
 * a través de enlaces (links). Cada elemento, llamado NODO (NODE),
 * contiene dos cosas:
 * 1. Los DATOS en sí (ej. un número, una estructura, etc.).
 * 2. Un PUNTERO al siguiente nodo en la secuencia.
 *
 * Piénsalo como un tren. Cada `Node` es un vagón. Contiene algo de carga
 * (los datos) y tiene un acoplamiento que lo conecta al siguiente vagón
 * (el puntero `next`). Todo lo que necesitamos saber para encontrar el
 * tren completo es dónde está el primer vagón. Este puntero al primer
 * vagón se llama CABECERA (HEAD).
 */

#include <stdio.h>
#include <stdlib.h> /* Para malloc() y free() */

/* --- Parte 1: El Bloque de Construcción - El Nodo ---
 *
 * Este es el plano para un solo "vagón" en nuestro tren.
 * Es una estructura AUTO-REFERENCIAL porque contiene un puntero a sí misma.
 */
typedef struct Node {
    int data;          /* Los datos que contiene este nodo */
    struct Node *next; /* Un puntero al siguiente nodo en la lista */
} Node;

/* --- Parte 2: Operaciones Core de la Lista ---
 * Escribiremos funciones para manejar las operaciones principales de la lista.
 */

/*
 * Crea un nodo nuevo, asigna memoria para él, e inicializa sus campos.
 * param data: dato entero a almacenar en el nodo nuevo.
 * return new_node: puntero al nodo recién creado.
 */
Node *create_node(int data) 
{
    /* Asignar memoria para un Node en el MONTÓN (HEAP). */
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Error: ¡Fallo la asignacion de memoria!\n");
        exit(1);
    }
    new_node->data = data; /* Establecer los datos. */
    new_node->next = NULL; /* El nodo nuevo no apunta a nada todavía. */
    return new_node;
}

/*
 * Inserta un nodo nuevo al comienzo de la lista.
 * param head_ref: Un puntero al puntero de la cabecera. Necesitamos este
 *                 doble puntero para poder modificar el puntero `head`
 *                 en la función principal (`main`).
 * param data: Los datos para el nodo nuevo.
 */
void insert_at_beginning(Node **head_ref, int data) 
{
    /* 1. Crear el nodo nuevo. */
    Node *new_node = create_node(data);

    /* 2. Apuntar el `next` del nodo nuevo a lo que `head` está apuntando. */
    new_node->next = *head_ref;

    /* 3. Actualizar `head` para que apunte a nuestro nodo nuevo, */
    /* haciéndolo el nuevo primer nodo. */
    *head_ref = new_node;
}

/*
 * Imprime todos los elementos de la lista de principio a fin.
 * param head: Un puntero al primer nodo de la lista.
 */
void print_list(Node *head) 
{
    Node *current = head; /* Empezar al principio. */

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next; /* Moverse al siguiente nodo. */
    }
    printf("NULL\n"); /* El final de la lista no apunta a nada. */
}

/*
 * Libera toda la memoria asignada para la lista para prevenir
 * fugas de memoria (memory leaks).
 * param head_ref: Un puntero al puntero de la cabecera.
 */
void free_list(Node **head_ref) 
{
    Node *current = *head_ref;
    Node *temp;

    while (current != NULL) {
        temp = current;          /* Guardar el nodo actual. */
        current = current->next; /* Moverse al siguiente. */
        free(temp);              /* Liberar el nodo guardado. */
    }

    /* Finalmente, establecer el puntero `head` original en main() a NULL. */
    *head_ref = NULL;
}

int main(void) 
{
    /* El puntero CABECERA (HEAD). Este es nuestro único punto de entrada */
    /* a la lista. Una lista vacía se representa por un puntero head NULL. */
    Node *head = NULL;

    printf("Construyendo la lista enlazada insertando al comienzo...\n");

    /* Insertar elementos. Ya que insertamos al comienzo, el último que */
    /* insertemos será el primero en la lista. */
    insert_at_beginning(&head, 30);
    insert_at_beginning(&head, 20);
    insert_at_beginning(&head, 10);

    printf("La lista actual es:\n");
    print_list(head);
    printf("\n");

    printf("Añadiendo otro elemento, 5...\n");
    insert_at_beginning(&head, 5);

    printf("La lista final es:\n");
    print_list(head);
    printf("\n");

    /* PASO CRÍTICO: Siempre limpiar la memoria cuando se termina. */
    printf("Liberando todos los nodos en la lista...\n");
    free_list(&head);

    printf("Lista despues de liberar:\n");
    print_list(head); /* Debería imprimir "NULL" */

    return 0;
}

/*
 * ====================================================================
 *                          - FIN DE LA LECCIÓN -               
 * ====================================================================
 *
 * Puntos Clave:
 *
 * 1. Una LISTA ENLAZADA es una estructura de datos dinámica hecha de
 *    NODOS enlazados por punteros.
 * 2. Un NODO contiene DATOS y un PUNTERO al siguiente nodo.
 * 3. El puntero CABECERA (HEAD) es el punto de entrada a toda la lista.
 *    Si `head` es `NULL`, la lista está vacía.
 * 4. Los Nodos se crean en el MONTÓN (HEAP) usando `malloc()`, lo que
 *    nos da la flexibilidad de hacer crecer o encoger la lista en tiempo
 *    de ejecución.
 * 5. Debido a que usamos `malloc()`, somos responsables de usar `free()`
 *    en cada nodo individual para prevenir fugas de memoria.
 * 6. Para modificar el puntero de la cabecera desde dentro de una función,
 *    debemos pasar su dirección (un puntero a un puntero, o `Node **`).
 *
 * Acabas de construir una de las estructuras de datos más fundamentales
 * en toda la ciencia de la computación. Entender las listas enlazadas
 * es clave para abordar estructuras más complejas como árboles, grafos,
 * y tablas hash.
 *
  */