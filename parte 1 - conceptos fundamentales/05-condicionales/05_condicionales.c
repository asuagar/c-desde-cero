/**
 * @file 05_condicionales.c
 * @brief Parte 1, Lección 5: Sentencias condicionales
 * @details
 * Esta lección presenta las sentencias condicionales,
 * que permiten que un programa tome decisiones y ejecute
 * distintos bloques de código según condiciones específicas.
 * 
 * @date 08-15-2025
 * @author DunamisMax <github.com/dunamismax>
 * @author Andrés Suárez <github.com/asuagar>
 * SPDX-License-Identifier: MIT
 */

/*
 * =============================================================================
 *                              - INICIO DE LA LECCIÓN -                        
 * =============================================================================
 *
 * Nuestros programas hasta ahora han sido lineales: ejecutan cada línea de código
 * de arriba abajo, siempre en el mismo orden. Para crear programas inteligentes,
 * debemos permitir que puedan tomar decisiones.
 *
 * Las SENTENCIAS CONDICIONALES permiten controlar el flujo de ejecución
 * de un programa. Usan los operadores relacionales y lógicos vistos en la
 * lección anterior para evaluar condiciones. Si una condición es verdadera
 * (valor distinto de cero), se ejecuta un bloque de código. Si es falsa (0),
 * se omite ese bloque y, opcionalmente, se ejecuta otro.
 *
 * La herramienta principal para esto es la sentencia `if`.
 */

#include <stdio.h>

int main(void) {
    // --- Parte 1: La sentencia `if` ---

    /*
     * La sentencia `if` es la forma más simple de condición.
     * Ejecuta un bloque de código solo si su condición es verdadera.
     *
     * Sintaxis:
     * if (condición) {
     *     // Código a ejecutar si la condición es verdadera
     * }
     */

    int score = 100;

    printf("--- Parte 1: La sentencia 'if' ---\n");
    printf("Puntuación inicial: %d\n", score);

    // Esta condición es verdadera, por lo tanto, se ejecuta el bloque.
    if (score == 100) {
        printf("¡Felicidades por una puntuación perfecta!\n");
    }

    // Esta condición es falsa, el bloque se omite.
    if (score > 100) {
        printf("Este mensaje no se mostrará.\n");
    }
    printf("\n");

    // --- Parte 2: La sentencia `if-else` ---

    /*
     * La cláusula `else` ofrece un bloque alternativo
     * cuando la condición del `if` es falsa.
     *
     * Sintaxis:
     * if (condición) {
     *     // Código si la condición es verdadera
     * } else {
     *     // Código si la condición es falsa
     * }
     */

    int number_to_check;

    printf("--- Parte 2: La sentencia 'if-else' ---\n");
    printf("Introduce un número entero: ");
    scanf("%d", &number_to_check);

    // Usamos el operador módulo `%` para comprobar si es par.
    // Si el resto al dividir por 2 es 0, el número es par.
    if (number_to_check % 2 == 0) {
        printf("%d es un número par.\n", number_to_check);
    } else {
        printf("%d es un número impar.\n", number_to_check);
    }
    printf("\n");

    // --- Parte 3: La cadena `if-else if-else` ---

    /*
     * Para verificar múltiples condiciones excluyentes, se encadenan
     * sentencias `else if`. El programa evalúa cada condición en orden
     * y ejecuta la primera que sea verdadera. El `else` final es opcional
     * y actúa como un caso por defecto.
     */

    int user_grade;

    printf("--- Parte 3: La cadena 'if-else if-else' ---\n");
    printf("Introduce tu nota numérica (0-100): ");
    scanf("%d", &user_grade);

    if (user_grade >= 90) {
        printf("Tu calificación es A.\n");
    } else if (user_grade >= 80) {
        printf("Tu calificación es B.\n");
    } else if (user_grade >= 70) {
        printf("Tu calificación es C.\n");
    } else if (user_grade >= 60) {
        printf("Tu calificación es D.\n");
    } else {
        printf("Tu calificación es F.\n");
    }

    /*
     * Nota sobre combinaciones lógicas:
     * Podemos usar operadores lógicos (`&&`, `||`)
     * para crear condiciones más complejas.
     * Ejemplo: comprobar si la nota es una B (80-89):
     */
    if (user_grade >= 80 && user_grade < 90) {
        printf("Es una B sólida.\n");
    }

    return 0;
}

/*
 * =============================================================================
 *                              - FIN DE LA LECCIÓN -                         
 * =============================================================================
 *
 * En esta lección aprendiste cómo dar “cerebro” a tu programa.
 *
 * Puntos clave:
 * - `if` ejecuta código solo si la condición es verdadera.
 * - `if-else` ofrece una alternativa si la condición es falsa.
 * - `if-else if-else` permite probar varias condiciones en orden
 *   y ejecutar solo la primera verdadera.
 * - Estas estructuras son la base de la lógica en programación.
 * 
 */
