/**
 * @file 06_bucles.c
 * @brief Parte 1, Lección 6: Bucles
 * @details
 * Esta lección introduce los bucles, estructuras de control
 * que permiten ejecutar un bloque de código repetidamente.
 * 
 * @date 2025-10-08
 * @author DunamisMax <github.com/dunamismax>
 * @author Andrés Suárez <github.com/asuagar>
 * SPDX-License-Identifier: MIT
 */

/*
 * =============================================================================
 *                            - INICIO DE LA LECCIÓN -                     
 * =============================================================================
 *
 * Imagina que necesitas imprimir “¡Hola!” cinco veces:
 * printf("¡Hola!\n");
 * printf("¡Hola!\n");
 * printf("¡Hola!\n");
 * printf("¡Hola!\n");
 * printf("¡Hola!\n");
 *
 * Esto es tedioso y no escalable. ¿Y si necesitaras hacerlo 500 veces?
 * Aquí entran los BUCLES. Un BUCLE es una estructura que repite una
 * secuencia de instrucciones hasta que se cumple una condición específica.
 * Cada ejecución del cuerpo del bucle se llama ITERACIÓN.
 *
 * C tiene tres tipos principales de bucles:
 * 1. El bucle `for`
 * 2. El bucle `while`
 * 3. El bucle `do-while`
 */

#include <stdio.h>

int main(void)
{
    // --- Parte 1: El bucle `for` ---

    /*
     * El bucle `for` es ideal cuando sabes exactamente cuántas veces
     * quieres repetir un bloque de código. Tiene tres partes separadas
     * por punto y coma dentro de los paréntesis:
     *
     * for (INICIALIZACIÓN; CONDICIÓN; POST-ITERACIÓN) {
     *     // Código a repetir
     * }
     *
     * 1. INICIALIZACIÓN: se ejecuta solo una vez antes del inicio del bucle.
     *    Normalmente se usa para declarar e inicializar una variable contador.
     * 
     * 2. CONDICIÓN: se evalúa antes de cada iteración. Si es verdadera,
     *    se ejecuta el cuerpo. Si es falsa, el bucle termina.
     * 
     * 3. POST-ITERACIÓN: se ejecuta después de cada iteración.
     *    Suele usarse para incrementar o decrementar el contador.
     *    `i++` es una forma abreviada de `i = i + 1`.
     */

    printf("--- Parte 1: Bucle 'for' (cuenta regresiva) ---\n");

    // Ejemplo: cuenta atrás desde 5 hasta 1.
    // Inicialización: int i = 5
    // Condición: i > 0
    // Post-iteración: i-- (decrementa en 1 después de cada ciclo)
    for (int i = 5; i > 0; i--) {
        printf("%d...\n", i);
    }
    printf("¡Despegue!\n\n");

    // --- Parte 2: El bucle `while` ---

    /*
     * El bucle `while` es más simple. Repite un bloque de código
     * MIENTRAS su condición siga siendo verdadera.
     * Es útil cuando no sabemos cuántas iteraciones serán necesarias.
     *
     * while (condición) {
     *     // Código a repetir
     * }
     *
     * La condición se evalúa ANTES de cada iteración.
     *
     * IMPORTANTE: asegúrate de que algo dentro del bucle modifique
     * la condición, o crearás un BUCLE INFINITO y el programa no terminará.
     */

    printf("--- Parte 2: Bucle 'while' (menú simple) ---\n");

    int menu_choice = 0;

    // El bucle se repite mientras el usuario no elija la opción 4 para salir.
    while (menu_choice != 4) {
        printf("Menú:\n");
        printf("1. Nuevo juego\n");
        printf("2. Cargar partida\n");
        printf("3. Opciones\n");
        printf("4. Salir\n");
        printf("Introduce tu elección: ");

        scanf("%d", &menu_choice); // Lee la opción del usuario.

        printf("Has elegido: %d\n\n", menu_choice);
    }
    printf("Gracias por jugar.\n\n");

    // --- Parte 3: El bucle `do-while` ---

    /*
     * El bucle `do-while` es una variante del `while`.
     * La diferencia es que la condición se evalúa AL FINAL del bucle.
     * Esto garantiza que el cuerpo del bucle se ejecute al menos una vez.
     *
     * Es perfecto para validación de entradas, ya que primero
     * se obtiene el dato y después se comprueba si es válido.
     */

    printf("--- Parte 3: Bucle 'do-while' (validación de entrada) ---\n");

    int secret_number;

    do {
        printf("Introduce un número entre 1 y 10: ");
        scanf("%d", &secret_number);

        // La comprobación se hace después de introducir el número.
        if (secret_number < 1 || secret_number > 10) {
            printf("Entrada no válida. Intenta de nuevo.\n");
        }

    } while (secret_number < 1 || secret_number > 10); // Se evalúa aquí.

    printf("Has introducido correctamente el número %d.\n", secret_number);

    return 0;
}

/*
 * =============================================================================
 *                               - FIN DE LA LECCIÓN -                         
 * =============================================================================
 *
 * En esta lección aprendiste cómo hacer que un programa repita tareas.
 *
 * Puntos clave:
 * - Los bucles ejecutan un bloque de código varias veces.
 * - El bucle `for` se usa cuando el número de repeticiones es conocido.
 *   Tiene inicialización, condición y post-iteración.
 * - El bucle `while` se usa cuando la condición depende de un evento.
 *   Se evalúa al inicio de cada iteración.
 * - El bucle `do-while` es similar al anterior, pero se ejecuta
 *   al menos una vez porque la condición se comprueba al final.
 *
 * Dominar los bucles es un gran paso hacia programas más complejos y útiles.
 * 
*/
