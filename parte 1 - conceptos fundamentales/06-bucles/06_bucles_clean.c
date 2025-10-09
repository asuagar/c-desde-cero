/* SPDX-License-Identifier: MIT */
/*
 * Filename: 06_bucles_clean.c
 *
 * Purpose:
 *   Parte 1, Lección 6: Bucles.
 *   Esta lección introduce los bucles, estructuras de control
 *   que permiten ejecutar un bloque de código de forma repetitiva.
 *
 * Design Notes:
 *   Ejemplo educativo que demuestra el uso de los bucles for, while
 *   y do-while en lenguaje C. Cada estructura se documenta y prueba
 *   por separado para favorecer la claridad y la trazabilidad.
 *
 * References:
 *   NASA/JPL Institutional Coding Standard for the C Programming Language.
 *
 * Author(s):
 *   DunamisMax    <github.com/dunamismax>
 *   Andrés Suárez <github.com/asuagar>
 *
 * Creation Date: 2025-10-08
 * Coding Standard: NASA/JPL C (4 espacios, llaves en nueva línea)
 */


#include <stdio.h>   /* Para printf() y scanf() */

/*
 * Función: main
 * -------------------------------------
 *  Punto de entrada del programa.
 *
 *  Muestra el funcionamiento de los bucles for, while y do-while,
 *  con ejemplos de control de flujo y validación de entrada del usuario.
 *
 *  Retorna:
 *    0  - Finalización correcta del programa.
 *    1  - Error en la entrada del usuario.
 */
int main(void)
{
    int menu = 0;
    int n = 0;

    /* --- Bucle for: cuenta regresiva --- */
    printf("--- for ---\n");
    for (int i = 5; i > 0; i--)
    {
        printf("%d...\n", i);
    }
    printf("¡Despegue!\n\n");

    /* --- Bucle while: menú interactivo --- */
    printf("--- while ---\n");
    while (menu != 4)
    {
        printf("1.Jugar  2.Cargar  3.Opciones  4.Salir\n> ");
        if (scanf("%d", &menu) != 1)
        {
            printf("Error: entrada no válida.\n");
            return 1;
        }
    }
    printf("Fin del juego.\n\n");

    /* --- Bucle do-while: validación de rango --- */
    printf("--- do-while ---\n");
    do
    {
        printf("Número (1–10): ");
        if (scanf("%d", &n) != 1)
        {
            printf("Error: entrada no válida.\n");
            return 1;
        }
    } while (n < 1 || n > 10);

    printf("Número válido: %d\n", n);

    /* Retornar código de éxito explícito */
    return 0;
}