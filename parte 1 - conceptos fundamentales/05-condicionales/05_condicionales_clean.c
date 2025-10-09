/**
 * @file 05_condicionales_clean.c
 * @brief Parte 1, Lección 5: Sentencias condicionales
 * @details
 * Esta lección presenta las sentencias condicionales,
 * que permiten que un programa tome decisiones y ejecute
 * distintos bloques de código según condiciones específicas.
 * 
 * @date 2025-10-08
 * @author DunamisMax <github.com/dunamismax>
 * @author Andrés Suárez <github.com/asuagar>
 * SPDX-License-Identifier: MIT
 * 
 * @note Estilo de codificación: NASA/JPL C (4 espacios, llaves en nueva línea).
 */

#include <stdio.h>   /* Para printf() y scanf() */

/*
 * Función: main
 * -------------------------------------
 *  Punto de entrada del programa.
 *
 *  Demuestra el uso de sentencias condicionales básicas en lenguaje C.
 *  Incluye ejemplos de if, if-else, y if-else if-else, además de una
 *  comparación lógica compuesta.
 *
 *  Retorna:
 *    0  - Finalización correcta del programa.
 *    1  - Error en la entrada del usuario.
 */
int main(void)
{
    int score = 100;
    int number_to_check = 0;
    int user_grade = 0;

    /* --- Condicional simple: if --- */
    printf("--- if ---\n");
    if (score == 100)
    {
        printf("Puntuación perfecta.\n");
    }

    /* --- Condicional doble: if-else --- */
    printf("--- if-else ---\n");
    printf("Introduce un número entero: ");
    if (scanf("%d", &number_to_check) != 1)
    {
        printf("Error: entrada no válida.\n");
        return 1;
    }

    if ((number_to_check % 2) == 0)
    {
        printf("%d es par.\n", number_to_check);
    }
    else
    {
        printf("%d es impar.\n", number_to_check);
    }

    /* --- Condicional múltiple: if-else if-else --- */
    printf("--- if-else if-else ---\n");
    printf("Introduce tu nota (0-100): ");
    if (scanf("%d", &user_grade) != 1)
    {
        printf("Error: entrada no válida.\n");
        return 1;
    }

    if (user_grade >= 90)
    {
        printf("A\n");
    }
    else if (user_grade >= 80)
    {
        printf("B\n");
    }
    else if (user_grade >= 70)
    {
        printf("C\n");
    }
    else if (user_grade >= 60)
    {
        printf("D\n");
    }
    else
    {
        printf("F\n");
    }

    /* Condición compuesta adicional */
    if ((user_grade >= 80) && (user_grade < 90))
    {
        printf("Es una B sólida.\n");
    }

    /* Retornar código de éxito explícito */
    return 0;
}
