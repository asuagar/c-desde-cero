/* SPDX-License-Identifier: MIT */
/*
 * Filename: 08_vectores_clean.c
 *
 * Purpose:
 *   Parte 1, Lección 8: Vectores (Arrays).
 *   Esta lección introduce los vectores, una estructura de datos
 *   fundamental para almacenar colecciones de elementos del mismo tipo.
 *
 * Design Notes:
 *   Ejemplo educativo que muestra cómo declarar, inicializar y recorrer
 *   vectores en lenguaje C. Se enfatiza la indexación basada en cero y
 *   las buenas prácticas de acceso seguro a los elementos.
 *
 * References:
 *   NASA/JPL Institutional Coding Standard for the C Programming Language.
 *
 * Author(s):
 *   DunamisMax    <github.com/dunamismax>
 *   Andrés Suárez <github.com/asuagar>
 *
 * Creation Date: 2025-10-15
 * Coding Standard: NASA/JPL C (4 spaces, braces on new line)
 */

#include <stdio.h>   /* Para printf() */

/*
 * Función: main
 * -------------------------------------
 *  Punto de entrada del programa.
 *
 *  Demuestra el uso de vectores (arrays) en lenguaje C mediante:
 *   - Parte 1: Declaración e inicialización.
 *   - Parte 2: Inicialización mediante listas.
 *   - Parte 3: Recorrido con bucles.
 *
 *  Retorna:
 *    0  - Finalización correcta del programa.
 */

int main(void)
{
    /* --- Parte 1: Declaración e inicialización de un vector --- */

    int high_scores[5];  
    printf("--- Parte 1: Asignación y acceso a elementos ---\n");

    /* Asignación directa por índice */
    high_scores[0] = 980;
    high_scores[1] = 950;
    high_scores[2] = 875;
    high_scores[3] = 820;
    high_scores[4] = 799;

    printf("La puntuación más alta es: %d\n", high_scores[0]);
    printf("La tercera puntuación más alta es: %d\n\n", high_scores[2]);

    /* --- Parte 2: Inicalización meidante listas  --- */

    printf("--- Parte 2: Uso de listas de inicialización ---\n");

    double temperatures[] = {72.5, 75.0, 69.8, 80.1, 85.3};
    char grades[] = {'A', 'B', 'A', 'C', 'B', 'A'};

    printf("La primera temperatura registrada fue: %.1f\n", temperatures[0]);
    printf("La calificación del cuarto alumno fue: %c\n\n", grades[3]);

    /* --- Parte 3: Recorrido de un vector --- */

    /* recorrido vector */
    printf("--- Parte 3: Recorrido con un bucle 'for' ---\n");
    printf("Todas las temperaturas registradas:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("  Día %d: %.1f\n", i + 1, temperatures[i]);
    }
    printf("\n");

    /* cálculo suma total */
    int total_score = 0;
    for (int i = 0; i < 5; i++)
    {
        total_score = total_score + high_scores[i];
    }
    printf("Suma de todas las puntuaciones: %d\n", total_score);

    return 0;
}
