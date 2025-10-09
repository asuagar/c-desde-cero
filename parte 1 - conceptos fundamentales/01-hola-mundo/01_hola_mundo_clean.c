/* SPDX-License-Identifier: MIT */
/*
 * Filename: 1_hola_mundo_clean.c
 *
 * Purpose:
 *   Lección 1: Hello World!
 *   Este archivo contiene tu primer programa en lenguaje C y
 *   constituye la primera lección del curso. La explicación se
 *   desarrolla mediante comentarios en el propio código, que deben
 *   leerse de arriba hacia abajo para comprender su funcionamiento.
 *
 * Design Notes:
 *   Ejemplo introductorio que muestra la estructura mínima de un
 *   programa en C, incluyendo la función principal main() y la
 *   instrucción printf() para generar salida en la consola.
 *
 * References:
 *   NASA/JPL Institutional Coding Standard for the C Programming Language.
 *
 * Author(s):
 *   DunamisMax    <github.com/dunamismax>
 *   Andrés Suárez <github.com/asuagar>
 *
 * Creation Date: 2025-10-08
 * Coding Standard: NASA/JPL C (4 spaces, braces on new line)
 */

#include <stdio.h>   /* Para la función printf() */

/*
 * Función: main
 * -------------------------------------
 *  Punto de entrada del programa.
 *
 *  Muestra un mensaje simple "Hello, World!"
 *  seguido de un salto de línea.
 *
 *  Retorna:
 *    0  - Finalización correcta del programa.
 */
int main(void)
{
    /* Muestra un mensaje en la salida estándar */
    printf("Hello, World!\n");

    /* Retorna un código de éxito explícito */
    return 0;
}