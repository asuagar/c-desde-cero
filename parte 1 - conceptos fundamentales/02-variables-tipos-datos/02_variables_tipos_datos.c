// SPDX-License-Identifier: MIT
/**
 * @file 2_variables_tipos_datos.c
 * @brief Lección 2: Variables y Tipos de Datos
 * @author Andrés Suárez <andsuarez@uvigo.es
 * @date 2025-10-06
 *
 * Este archivo introduce los conceptos fundamentales de variables y tipos de datos.
 * Aprendemos cómo almacenar información en memoria y mostrarla en la consola.
 */

/*
 * =============================================================================
 *                                    - INICIO LECCIÓN -                     
 * =============================================================================
 *
 * En la lección anterior, imprimimos un mensaje fijo. Para escribir programas,
 * necesitamos una forma de almacenar y manipular datos que puedan cambiar. Aquí es
 * donde entran las variables.
 *
 * ¿QUÉ ES UNA VARIABLE?
 * 
 * Una VARIABLE es una ubicación de memoria con nombre. Piensa en ella como una caja
 * etiquetada donde puedes guardar una información. Le das un nombre y puedes cambiar
 * el contenido de la caja (el valor) mientras se ejecuta el programa.
 *
 * ¿QUÉ ES UN TIPO DE DATO?
 * 
 * Un TIPO DE DATO especifica el tipo de información que una variable puede contener.
 * C es un lenguaje "de tipado estático", lo que significa que debes indicar al
 * compilador el tipo de cada variable que creas. Esto ayuda a reservar la cantidad
 * adecuada de memoria y asegura el uso correcto de la variable.
 *
 * El proceso de crear una variable se llama DECLARACIÓN.
 * El proceso de darle su primer valor se llama INICIALIZACIÓN.
 */

#include <stdio.h>

int main(void)
{
    // El cuerpo de main es donde declararemos y usaremos nuestras variables.

    // --- Parte 1: El Entero (int) ---

    /*
     * Un ENTERO es un número completo (sin punto decimal). El tipo `int` se usa
     * para almacenarlos. En inglés, entero se traduce "integer".
     *
     * A continuación, DECLARAMOS una variable llamada `player_score` de tipo `int`.
     * Esto le dice al compilador: "Reserva un espacio en memoria para un entero,
     * y lo llamaré `player_score`."
     */

    int player_score; // Declaración

    /*
     * Ahora INICIALIZAMOS la variable asignándole un valor mediante el operador `=`.
     */

    player_score = 1250; // Inicialización

    /*
     * Para imprimir el valor de una variable, usamos `printf` con 
     * un ESPECIFICADOR DE FORMATO. Es un marcador dentro del texto 
     * que indica qué tipo de dato se imprimirá.
     *
     * `%d` es el especificador para un entero decimal con signo (`int`).
     * La variable `player_score` se pasa como segundo argumento y sustituirá a `%d`.
     */

    printf("Player score: %d\n", player_score);

    // También puedes declarar e inicializar en una sola línea.

    int number_of_lives = 3;
    printf("Number of lives: %d\n", number_of_lives);
    printf("\n"); // Línea en blanco para separar

    // --- Parte 2: Número de punto flotante doble precisión (double) ---

    /*
     * Para almacenar números con decimales, usamos tipos de punto flotante.
     * El más común es `double` (“doble precisión”).
     * Tiene más precisión que su versión `float`.
     * En este curso, preferiremos `double` para los decimales.
     *
     * `%f` es el especificador para `double` (y también `float`).
     */

    double item_price = 19.99; // Declaración e inicialización
    printf("The price of the magic sword is: $%f\n", item_price);

    /*
     * Por defecto, `%f` imprime muchos ceros. Podemos limitar el número de decimales
     * modificando el especificador: `%.2f` imprime solo 2 cifras tras el punto.
     */

    printf("The price, formatted neatly, is: $%.2f\n", item_price);
    printf("\n");

    // --- Parte 3: El Carácter (char) ---

    /*
     * El tipo `char` almacena un solo CARÁCTER: letra, número o símbolo.
     *
     * Un LITERAL DE CARÁCTER se encierra entre comillas simples, como 'A'.
     * Es distinto de una cadena, que usa comillas dobles.
     *
     * `%c` es el especificador para `char`.
     */

    char player_grade = 'A'; // Declaración e inicialización
    printf("Player's performance grade: %c\n", player_grade);

    // --- Parte 4: Combinándolo todo ---

    /*
     * Podemos imprimir varias variables en una sola llamada a `printf`.
     * Solo debemos mantener el orden entre especificadores y variables.
     */

    printf("Summary: Player with %d lives and a grade of '%c' has a score of %d.\n",
           number_of_lives, player_grade, player_score);

    return 0; // Indica ejecución correcta
}

/*
 * =============================================================================
 *                             - FIN DE LECCIÓN -                               
 * =============================================================================
 *
 * En esta lección aprendiste tres tipos básicos de datos:
 * - `int` para números enteros.
 * - `double` para números decimales.
 * - `char` para caracteres individuales.
 *
 * También aprendiste a DECLARAR variables, INICIALIZARLAS y mostrarlas con `printf`
 * usando ESPECIFICADORES DE FORMATO (`%d`, `%f`, `%c`).
 * 
 */
