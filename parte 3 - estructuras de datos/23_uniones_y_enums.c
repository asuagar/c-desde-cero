 /*
 * 23_unioness_y_enums.c - Parte 3, Lección 23: Uniones y Enumeraciones
 *
 * Este archivo sirve como lección y demostración sobre enums y unions.
 * Explica cómo estos tipos de datos especializados se usan para crear
 * constantes legibles y para almacenar datos de manera eficiente en memoria.
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
 *                       - INICIO DE LA LECCIÓN -               
 * ====================================================================
 *
 * Hoy veremos dos tipos especiales de datos: `enum` y `union`.
 * Aunque se parecen a las estructuras (`struct`), resuelven problemas
 * muy diferentes.
 *
 * - ENUM (Enumeración):
 *   Su objetivo es hacer el código más LEGIBLE y SEGURO. Un `enum`
 *   crea un conjunto de constantes enteras con nombre. En lugar de usar
 *   números mágicos como 0, 1 o 2, puedes usar nombres significativos
 *   como `SUCCESS`, `PENDING` o `FAILURE`.
 *
 * - UNION:
 *   Su objetivo es la EFICIENCIA DE MEMORIA. Una `union` permite
 *   almacenar distintos tipos de datos en la MISMA posición de memoria,
 *   pero solo uno a la vez. Mientras una estructura reserva espacio
 *   para todos sus miembros, una unión solo reserva el tamaño de su
 *   miembro más grande.
 */

#include <stdio.h>
#include <stdint.h> /* Para enteros de ancho fijo como uint8_t */

/* --- Parte 1: Enums para código legible --- 
/* Definimos una enumeración para representar diferentes estados. */
typedef enum {
    STATE_PENDING,    /* Valor asignado automáticamente: 0 */
    STATE_PROCESSING, /* Valor asignado automáticamente: 1 */
    STATE_SUCCESS,    /* Valor asignado automáticamente: 2 */
    STATE_FAILURE     /* Valor asignado automáticamente: 3 */
} SystemState;

/* --- Parte 2: Unions para eficiencia de memoria --- 
/* Esta unión puede almacenar UNO de tres tipos, pero no varios a la vez. */
typedef union {
    int i;
    double d;
    char c;
} DataValue;

/* --- Parte 3: Uniones etiquetadas (Tagged Unions) 
 * El problema de las uniones es que no sabes qué miembro es válido.
 * La solución es una UNIÓN ETIQUETADA: se envuelve la unión dentro
 * de una estructura junto con un enum que indica el tipo actual. 
 */
typedef enum {
    TYPE_INT,
    TYPE_DOUBLE,
    TYPE_CHAR
} DataType;

typedef struct {
    DataType type;   /* Etiqueta que indica qué contiene la unión */
    DataValue value; /* Unión que almacena el dato real */
} TaggedValue;

/* Función auxiliar para imprimir una unión etiquetada de forma segura. */
void print_tagged_value(TaggedValue tv)
{
    switch (tv.type) {
    case TYPE_INT:
        printf("TaggedValue es un INT: %d\n", tv.value.i);
        break;
    case TYPE_DOUBLE:
        printf("TaggedValue es un DOUBLE: %f\n", tv.value.d);
        break;
    case TYPE_CHAR:
        printf("TaggedValue es un CHAR: '%c'\n", tv.value.c);
        break;
    default:
        printf("TaggedValue tiene un tipo desconocido.\n");
    }
}

int main(void)
{
    printf("--- Parte 1: Uso de Enums ---\n");
    SystemState current_state = STATE_PROCESSING;

    /* Mucho más legible que `if (current_state == 1)` */
    if (current_state == STATE_PROCESSING)
        printf("El estado actual del sistema es: PROCESSING\n\n");

    printf("--- Parte 2: Uso de Unions ---\n");
    DataValue data;

    printf("Tamaño de la unión DataValue: %zu bytes\n", sizeof(DataValue));
    printf("Tamaño de un double: %zu bytes\n", sizeof(double));
    printf("¡La unión ocupa el tamaño de su miembro más grande!\n\n");

    /* Guardamos un entero */
    data.i = 123;
    printf("Se ha almacenado un int: data.i = %d\n", data.i);

    /* Guardamos ahora un double. Sobrescribe el entero. */
    data.d = 987.654;
    printf("Se ha almacenado un double: data.d = %f\n", data.d);

    /* El valor del entero queda corrupto. */
    printf("El valor del int ahora es basura: data.i = %d\n\n", data.i);

    printf("--- Parte 3: Uso de Uniones Etiquetadas ---\n");

    /* Creamos un valor etiquetado para un entero */
    TaggedValue int_val;
    int_val.type = TYPE_INT;
    int_val.value.i = 42;
    print_tagged_value(int_val);

    /* Creamos otro valor etiquetado para un double */
    TaggedValue double_val;
    double_val.type = TYPE_DOUBLE;
    double_val.value.d = 3.14159;
    print_tagged_value(double_val);

    return 0;
}

/*
 * ====================================================================
 *                          - FIN DE LA LECCIÓN -               
 * ====================================================================
 * 
 * Ideas clave:
 *
 * 1) Las ENUMERACIONES crean constantes enteras con nombre, haciendo el
 *    código más legible y menos propenso a errores. Son ideales para
 *    `switch` o para representar estados fijos.
 *
 * 2) Las UNIONES permiten que varios miembros compartan la misma memoria.
 *    Ahorra memoria cuando solo necesitas almacenar un tipo de dato
 *    a la vez.
 *
 * 3) El patrón más potente es la UNIÓN ETIQUETADA: una estructura que
 *    combina un `union` y un `enum`. El `enum` indica qué campo del
 *    `union` es válido, permitiendo usarlo de forma segura.
 *
 * Comprender cuándo usar estos tipos especializados es una marca de
 * dominio en C.
 *
 */
