/**
 * @file 09_cadenas.c
 * @brief Parte 1, Lección 9: Cadenas de caracteres (Strings)
 * @details
 * Esta lección explica cómo trabajar con cadenas, uno de los tipos
 * de datos más comunes en programación.
 * 
 * @date 10-15-2025
 * @author DunamisMax <github.com/dunamismax>
 * @author Andrés Suárez <github.com/asuagar>
 * SPDX-License-Identifier: MIT
 */

/*
 * =============================================================================
 *                           - INICIO DE LA LECCIÓN -                     
 * =============================================================================
 *
 * Hasta ahora solo usamos cadenas literales directamente en `printf`.
 * No las hemos almacenado ni manipulado.
 *
 * IDEA PRINCIPAL:
 * C no tiene un tipo de dato `string` incorporado. En su lugar,
 * una CADENA en C es simplemente un VECTOR de caracteres (`char`).
 * Pero ¿cómo sabe el programa dónde termina la cadena?
 *
 * EL TERMINADOR NULO:
 * Las cadenas en C siguen una convención: terminan con un
 * carácter especial  llamado TERMINADOR NULO `\0`. Este carácter
 * marca el final de la cadena. Por ejemplo, la cadena "Hello"
 * se guarda como ['H', 'e', 'l', 'l', 'o', '\0']. Ocupa 
 * 6 caracteres, no 5. ¡Este detalle es esencial!
 *
 * Todas las funciones estándar de C que manejan cadenas dependen
 * de ese `\0`.
 */

#include <stdio.h>
#include <string.h> // Biblioteca necesaria para funciones de manejo de cadenas. 

int main(void)
{
    // --- Parte 1: Declarar e imprimir cadenas ---

    /*
     * La forma más sencilla de declarar e inicializar una cadena
     * es usando un literal entre comillas. El compilador añade
     * automáticamente el terminador nulo `\0`.
     */

    char greeting[] = "Hello, C programmer!";

    printf("--- Parte 1: Declarar e imprimir cadenas ---\n");

    /*
     * El especificador de formato `%s` en `printf` sirve para 
     * imprimir cadenas. `printf` recorre el vector de 
     * caracteres hasta encontrar `\0`.
     */

    printf("Cadena de saludo: %s\n", greeting);

    /*
     * Podemos demostrar la existencia del terminador nulo creando
     * una cadena manualmente, carácter a carácter.
     */

    char name[] = {'A', 'l', 'i', 'c', 'e', '\0'};
    printf("Nombre creado manualmente: %s\n\n", name);

    // --- Parte 2: La biblioteca <string.h> ---

    /*
     * Dado que las cadenas son tan comunes, C ofrece funciones 
     * específicas para manipularlas. Todas se encuentran en la 
     * biblioteca `<string.h>`.
     */

    printf("--- Parte 2: Funciones de cadena ---\n");

    // strlen() — Longitud de una cadena.
    // Cuenta los caracteres antes del terminador nulo.
    char message[] = "This is a test.";
    // El tamaño es 15 aunque exista '\0'. Este no se cuenta.
    printf("Mensaje: \"%s\"\n", message);
    printf("Longitud del mensaje (strlen): %zu\n", strlen(message));
    printf("\n");
    // Nota: strlen devuelve un tipo especial de entero 
    // llamado `size_t`. Se usa `%zu` para imprimir su valor
    // correctamente y evitar avisos.

    // --- Parte 3: Copiar y concatenar cadenas ---

    printf("--- Parte 3: Copiar y concatenar ---\n");

    /*
     * strcpy() — Copiar cadenas.
     * NO SE PUEDE asignar una cadena con `=`.
     * Se deben copiar los caracteres uno a uno con esta función.
     * ¡El destino debe tener espacio suficiente para incluir el `\0`!
     */

    char destination[50];
    char source[] = "Some text to be copied.";

    strcpy(destination, source);
    printf("Resultado de strcpy: %s\n", destination);

    /*
     * strcat() — Concatenar cadenas.
     * Añade el contenido de una cadena al final de otra.
     * Nuevamente, el destino debe tener espacio suficiente.
     */

    char full_greeting[50] = "Welcome, ";
    char user[] = "dunamismax";

    strcat(full_greeting, user);
    printf("Resultado de strcat: %s\n\n", full_greeting);

    // --- Parte 4: Comparar cadenas ---

    printf("--- Parte 4: Comparar cadenas ---\n");

    /*
     * strcmp() — Comparar cadenas.
     * No se deben comparar cadenas con `==`,
     * `if (str1 == str2)` es incorrecto, puesto que 
     * compara direcciones de memoria, no contenido.
     *
     * strcmp() compara carácter por carácter de forma lexicográfica:
     *   - Devuelve 0 si las cadenas son iguales.
     *   - Valor negativo si la primera es "menor".
     *   - Valor positivo si la primera es "mayor".
     */

    char pass1[] = "password123";
    char pass2[] = "Password123"; /* Mayúsculas importan. */
    char pass3[] = "password123";

    if (strcmp(pass1, pass2) == 0) {
        printf("\"%s\" y \"%s\" son iguales.\n", pass1, pass2);
    } else {
        printf("\"%s\" y \"%s\" son diferentes.\n", pass1, pass2);
    }

    if (strcmp(pass1, pass3) == 0) {
        printf("\"%s\" y \"%s\" son iguales.\n", pass1, pass3);
    }

    return 0;
}

/*
 * =============================================================================
 *                               - FIN DE LA LECCIÓN -                        
 * =============================================================================
 *
 * En esta lección aprendiste a trabajar con cadenas de caracteres.
 *
 * Puntos clave:
 * - Una cadena en C es un vector `char` terminado en `\0`.
 * - `%s` imprime cadenas en `printf`.
 * - `<string.h>` ofrece funciones como:
 *     strlen() → longitud sin contar el `\0`.
 *     strcpy() → copia una cadena.
 *     strcat() → concatena cadenas.
 *     strcmp() → compara contenidos.
 */
