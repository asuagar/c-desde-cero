/* SPDX-License-Identifier: MIT */
/*
 * Filename: 4_operadores_basicos_clean.c
 *
 * Purpose:
 *   Parte 1, Lección 4: Operadores básicos.
 *   Esta lección explica los operadores fundamentales en lenguaje C
 *   utilizados para realizar cálculos y comparaciones.
 *
 * Design Notes:
 *   Ejemplo educativo que demuestra el uso de operadores aritméticos,
 *   relacionales, lógicos y de precedencia. El código está organizado
 *   para resaltar la legibilidad y la claridad del flujo de ejecución.
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

#include <stdio.h>   /* Para printf() */

/*
 * Función: main
 * -------------------------------------
 *  Punto de entrada del programa.
 *
 *  Demuestra el uso de operadores aritméticos, relacionales
 *  y lógicos en lenguaje C, así como el efecto de la precedencia
 *  en expresiones compuestas.
 *
 *  Retorna:
 *    0  - Finalización correcta del programa.
 */
int main(void)
{
    int a = 10;
    int b = 3;
    double precise_division = 0.0;
    int is_player_alive = 1;
    int has_key = 0;

    /* --- Operadores aritméticos --- */
    printf("--- Operadores aritméticos ---\n");
    printf("a = %d, b = %d\n", a, b);
    printf("a + b = %d, a - b = %d, a * b = %d\n", a + b, a - b, a * b);
    printf("a / b = %d, a %% b = %d\n", a / b, a % b);

    precise_division = (double)a / b;
    printf("División flotante = %f\n\n", precise_division);

        /* --- Operadores relacionales --- */
    printf("--- Operadores relacionales ---\n");
    printf("a == 10: %d, a == b: %d, a != b: %d\n", (a == 10), (a == b), (a != b));
    printf("a > b: %d, a < b: %d, a >= 10: %d, b <= 3: %d\n\n",
           (a > b), (a < b), (a >= 10), (b <= 3));

    /* --- Operadores lógicos --- */
    printf("--- Operadores lógicos ---\n");
    printf("AND: %d  OR: %d  NOT: %d\n\n",
           (is_player_alive && has_key),
           (is_player_alive || has_key),
           (!has_key));

    /* --- Precedencia de operadores --- */
    printf("--- Precedencia ---\n");
    printf("5 + 2 * 10 = %d, (5 + 2) * 10 = %d\n", (5 + 2 * 10), ((5 + 2) * 10));

    /* Retornar código de éxito explícito */
    return 0;
}