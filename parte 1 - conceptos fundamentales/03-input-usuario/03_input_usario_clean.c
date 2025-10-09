/* SPDX-License-Identifier: MIT */
/*
 * Filename: 3_input_usuario_clean.c
 *
 * Purpose:
 *   Lección 3: Entrada del Usuario.
 *   Esta lección muestra cómo hacer que los programas sean interactivos
 *   leyendo datos introducidos por el usuario desde el teclado.
 *
 * Design Notes:
 *   Ejemplo educativo centrado en el uso de la función scanf()
 *   para capturar distintos tipos de datos (int, double, char).
 *   Se enfatiza la validación de entradas y la claridad del flujo del programa.
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

#include <stdio.h>   /* Para printf() y scanf() */

/*
 * Función: main
 * -------------------------------------
 *  Punto de entrada del programa.
 *
 *  Demuestra cómo realizar entradas básicas con scanf()
 *  para distintos tipos de variables: int, double y char.
 *
 *  Retorna:
 *    0  - Finalización correcta del programa.
 *    1  - Error en la entrada del usuario.
 */
int main(void)
{
    int user_age = 0;
    double user_gpa = 0.0;
    char favorite_letter = '\0';

    /* Leer un valor entero */
    printf("Enter your age: ");
    if (scanf("%d", &user_age) != 1)
    {
        printf("Error: entrada no válida.\n");
        return 1;
    }
    printf("Age: %d\n\n", user_age);

    /* Leer un valor de punto flotante */
    printf("Enter your GPA: ");
    if (scanf("%lf", &user_gpa) != 1)
    {
        printf("Error: entrada no válida.\n");
        return 1;
    }
    printf("GPA: %.2f\n\n", user_gpa);

    /* Leer un carácter individual */
    printf("Enter your favorite letter: ");
    if (scanf(" %c", &favorite_letter) != 1)
    {
        printf("Error: entrada no válida.\n");
        return 1;
    }
    printf("Letter: '%c'\n", favorite_letter);

    /* Retornar código de éxito explícito */
    return 0;
}