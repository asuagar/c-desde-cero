// SPDX-License-Identifier: MIT
/**
 * @file 3_input_usuario.c
 * @brief Lección 3: Entrada del Usuario
 * @author Andrés Suárez <andsuarez@uvigo.es>
 * @date 2025-10-06
 *
 * @details
 * Esta lección muestra cómo hacer que los programas sean interactivos
 * leyendo la entrada desde el teclado del usuario.
 */

/*
 * =============================================================================
 *                            - INICIO DE LECCIÓN -                             
 * =============================================================================
 *
 * Hasta ahora, nuestros programas solo imprimían información.
 * Para que sean realmente útiles, deben interactuar con el usuario.
 *
 * LA FUNCIÓN `scanf`
 * 
 * El complemento de `printf` es `scanf`, usada para leer datos.
 * `scanf` lee entradas formateadas desde la entrada estándar (el teclado).
 *
 * Igual que `printf`, usa ESPECIFICADORES DE FORMATO para saber qué tipo de
 * dato debe leer. Sin embargo, requiere una precaución importante que veremos.
 */

#include <stdio.h>

int main(void)
{
    // --- Parte 1: Leer un Entero ---

    /*
     * Primero declaramos una variable para guardar la entrada.
     * Declaramos `user_age` sin inicializarla; su valor lo dará el usuario.
     */

    int user_age;

    /*
     * Es buena práctica mostrar un mensaje (prompt) para guiar al usuario.
     */

    printf("Please enter your age (as a whole number): ");

    /*
     * Llamamos a `scanf`. Este es el punto clave de la lección.
     *
     * - `"%d"`: especificador de formato para un entero. Le dice a `scanf`
     * que leerá un entero introducido desde el teclado.
     * 
     * - `&user_age`: el operador `&` es el OPERADOR DIRECCIÓN-DE DE MEMORIA.
     * Obtiene la dirección de memoria de la variable `user_age`.
     *
     * ¿POR QUÉ SE NECESITA `&`?
     * 
     * `scanf` necesita saber *dónde* guardar el dato leído.
     * Si se pasara `user_age` sin `&`, `scanf`solo recibiría su valor actual.
     * Con `&user_age`, `scanf` recibe la *dirección* de la caja donde almacenar
     * el dato introducido por el teclado.
     */

    scanf("%d", &user_age);

    // Comprobamos el valor leído.

    printf("Thank you. You entered %d.\n", user_age);
    printf("\n");

    // --- Parte 2: Leer un Double ---

    /*
     * El patrón es el mismo para otros tipos de datos.
     * Solo necesitamos cambiar el tipo de variable y el especificador de formato.
     *
     * IMPORTANTE: en `scanf`, el especificador de formato para un `double` es `%lf`
     * (que significa “long float”). Esto es DIFERENTE de `printf`,
     * que usa `%f` para un `double`. Es un punto de confusión común.
     */

    double user_gpa;
    printf("Please enter your GPA (e.g., 3.8): ");
    scanf("%lf", &user_gpa); // Usa %lf al leer un double.

    printf("Your GPA is %.2f.\n", user_gpa); // Usa %f al imprimir.
    printf("\n");

    // --- Parte 3: Un error común con `scanf` y la lectura de un carácter ---

    /*
     * `scanf` a veces puede comportarse de manera inesperada debido a cómo maneja
     * los espacios en blanco (como espacios, tabuladores y saltos de línea).
     *
     * Cuando escribiste tu GPA y presionaste Enter, el carácter `\n`
     * (salto de línea) quedó almacenado en el BÚFER DE ENTRADA.
     * Una llamada posterior a `scanf` para leer un carácter (`%c`)
     * leería ese salto de línea sobrante en lugar de esperar a que escribas
     * un nuevo carácter.
     *
     * LA SOLUCIÓN: para corregirlo, colocamos un espacio antes de `%c`
     * en la cadena de formato: `" %c"`. Ese espacio inicial le indica a `scanf`
     * que “ignore todos los caracteres en blanco previos antes de leer el carácter”.
     * Es un truco fundamental.
     */

   char favorite_letter;
    printf("Please enter your favorite letter: ");
    scanf(" %c", &favorite_letter); // El espacio antes de %c es clave.

    printf("Your favorite letter is '%c'.\n", favorite_letter);

    return 0;
}

/*
 * =============================================================================
 *                             - FIN DE LECCIÓN -                               
 * =============================================================================
 *
 * En esta lección aprendiste los fundamentos para hacer tus programas interactivos.
 *
 * Puntos clave:
 * - La función `scanf()` lee entrada formateada desde el teclado.
 * - `scanf()` requiere el OPERADOR DE DIRECCIÓN `&` antes del nombre de la variable
 *   para saber *dónde* almacenar la entrada.
 * - Los especificadores de formato de `scanf()` pueden ser diferentes de `printf()`.
 *   - Para `double`: usa `%lf` con `scanf`, pero `%f` con `printf`.
 * - `scanf()` puede dejar caracteres de salto de línea en el búfer de entrada,
 *   lo que puede causar problemas. El truco de `" %c"` (con un espacio al inicio)
 *   se utiliza para evitarlo al leer caracteres.
 */
