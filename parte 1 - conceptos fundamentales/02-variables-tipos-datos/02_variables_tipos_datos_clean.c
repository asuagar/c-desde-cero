/* SPDX-License-Identifier: MIT */
/*
 * Filename: 2_variables_tipos_datos_clean.c
 *
 * Purpose:
 *   Lección 2: Variables y Tipos de Datos.
 *   Este archivo introduce los conceptos fundamentales de variables
 *   y tipos de datos en lenguaje C. Se explica cómo almacenar
 *   información en memoria y mostrarla en la consola.
 *
 * Design Notes:
 *   Ejemplo educativo que demuestra la declaración e inicialización
 *   de variables de tipo int, double y char. Se utiliza la función
 *   printf() para mostrar los valores en pantalla.
 *
 * References:
 *   NASA/JPL Institutional Coding Standard for the C Programming Language.
 *
 * Author(s):
 *   DunamisMax    <github.com/dunamismax>
 *   Andrés Suárez <github.com/asuagar>
 *
 * Creation Date: 2025-10-06
 * Coding Standard: NASA/JPL C (4 spaces, braces on new line)
 */

/*
 * Función: main
 * -------------------------------------
 *  Punto de entrada del programa.
 *
 *  Demuestra cómo declarar, inicializar e imprimir variables
 *  de tipos básicos en lenguaje C: int, double y char.
 *
 *  Retorna:
 *    0  - Finalización correcta del programa.
 */

int main(void)
{
    /* Entero: número sin decimales */
    int player_score = 1250;
    printf("Player score: %d\n", player_score);

    /* Declaración e inicialización en una sola línea */
    int number_of_lives = 3;
    printf("Number of lives: %d\n", number_of_lives);
    printf("\n");

    /* Doble precisión: números con decimales */
    double item_price = 19.99;
    printf("Price: $%.2f\n", item_price);
    printf("\n");

    /* Carácter individual */
    char player_grade = 'A';
    printf("Grade: %c\n", player_grade);

    /* Imprimir un resumen con todas las variables */
    printf("Summary: %d lives, grade '%c', score %d\n",
           number_of_lives, player_grade, player_score);

    /* Retornar código de éxito explícito */
    return 0;
}