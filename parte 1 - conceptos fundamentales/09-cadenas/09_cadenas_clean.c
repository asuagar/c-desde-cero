/* SPDX-License-Identifier: MIT */
/*
 * Filename: 09_cadenas.c
 *
 * Purpose:
 *   Parte 1, Lección 9: Cadenas de caracteres (Strings).
 *   Introduce el manejo de cadenas en lenguaje C, su estructura
 *   como vectores de caracteres y el uso de funciones estándar.
 *
 * Design Notes:
 *   Ejemplo educativo que muestra la creación, impresión,
 *   copia, concatenación y comparación de cadenas. Se enfatiza
 *   la presencia del terminador nulo '\0' y el uso de <string.h>.
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

#include <stdio.h>    /* Para printf() */
#include <string.h>   /* Para funciones de manejo de cadenas */

/*
 * Función: main
 * -------------------------------------
 *  Punto de entrada del programa.
 *
 *  Descripción:
 *    - Declara e imprime cadenas simples.
 *    - Usa funciones de <string.h> (strlen, strcpy, strcat, strcmp).
 *    - Demuestra el uso del terminador nulo '\0'.
 *
 *  Retorna:
 *    0  – Finalización correcta.
 */
int main(void)
{
    char greeting[] = "Hello, C programmer!";
    char name[] = {'A', 'l', 'i', 'c', 'e', '\0'};
    char message[] = "This is a test.";
    char destination[50];
    char source[] = "Some text to be copied.";
    char full_greeting[50] = "Welcome, ";
    char user[] = "dunamismax";
    char pass1[] = "password123";
    char pass2[] = "Password123";
    char pass3[] = "password123";

    printf("--- Parte 1: Declarar e imprimir cadenas ---\n");
    printf("Cadena de saludo: %s\n", greeting);
    printf("Nombre manual: %s\n\n", name);

    printf("--- Parte 2: Funciones de cadena ---\n");
    printf("Mensaje: \"%s\"\n", message);
    printf("Longitud del mensaje (strlen): %zu\n\n", strlen(message));

    printf("--- Parte 3: Copiar y concatenar ---\n");
    strcpy(destination, source);
    printf("Resultado de strcpy: %s\n", destination);

    strcat(full_greeting, user);
    printf("Resultado de strcat: %s\n\n", full_greeting);

    printf("--- Parte 4: Comparar cadenas ---\n");

    if (strcmp(pass1, pass2) == 0)
    {
        printf("\"%s\" y \"%s\" son iguales.\n", pass1, pass2);
    }
    else
    {
        printf("\"%s\" y \"%s\" son diferentes.\n", pass1, pass2);
    }

    if (strcmp(pass1, pass3) == 0)
    {
        printf("\"%s\" y \"%s\" son iguales.\n", pass1, pass3);
    }

    return 0;
}
