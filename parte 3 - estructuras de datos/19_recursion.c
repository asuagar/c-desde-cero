 /*
 * 19_recursion.c - Parte 3, Recursión
 *
 * Este archivo es una lección y demostración sobre la recursión en C.
 * Explica el concepto de una función que se llama a sí misma,
 * la importancia de un caso base (base case), y cómo la recursión
 *  puede ser una alternativa elegante a los bucles (loops) para
 *  ciertos problemas.
 *
 * Fecha: 15-10-2025
 * Autores:
 *   DunamisMax <github.com/dunamismax>
 *   Andrés Suárez <github.com/asuagar>
 *
 * SPDX-License-Identifier: MIT
 */

/*
 * ====================================================================
 *                         - INICIO DE LA LECCIÓN -              
 * ====================================================================
 *
 * Hasta ahora, cuando has necesitado repetir una tarea, has usado un bucle
 * (`for` o `while`). Hoy, vamos a aprender una alternativa potente y
 * elegante: la RECURSIÓN.
 *
 * ¿QUÉ ES LA RECURSIÓN?
 * 
 * La RECURSIÓN es el proceso de una función llamándose a sí misma.
 * Piénsalo como un conjunto de muñecas rusas (matrioskas). Abres una muñeca
 * para encontrar una un poco más pequeña dentro. Abres esa para encontrar
 * una aún más pequeña, y así sucesivamente, hasta que llegas a la muñeca
 * más pequeña y sólida que no se puede abrir.
 *
 * En la programación, una función recursiva funciona de la misma manera.
 * Tiene dos partes esenciales:
 *
 * 1. EL CASO BASE: Esta es la condición que DETIENE la recursión. Es la
 * "muñeca más pequeña" que no se llama a sí misma de nuevo. Sin un
 * caso base, una función recursiva se llamaría a sí misma para siempre,
 * provocando un fallo. Esta es la parte MÁS IMPORTANTE de cualquier
 * función recursiva.
 *
 * 2. EL PASO RECURSIVO: Aquí es donde la función se llama a sí misma, pero
 * con un argumento modificado que la acerca un paso al caso base. Es el
 * acto de "abrir la muñeca para encontrar la siguiente más pequeña".
 */

#include <stdio.h>

/* --- Parte 1: Una simple cuenta atrás recursiva ---
 *
 * Esta función contará hacia atrás desde un número `n` hasta 1,
 * luego imprimirá "¡Despegue!" ("Blastoff!"). Es una manera simple de ver
 * el caso base y el paso recursivo en acción.
 */

void countdown(int n)
{
    /* CASO BASE: Si n es 0 o menos, detenemos la recursión. */
    if (n <= 0) {
        printf("Blastoff!\n");
        return; /* Detener. */
    }

    /* PASO RECURSIVO: */
    printf("%d...\n", n);
    countdown(n - 1); /* La función se llama a sí misma con un número menor. */
}

/*
 * --- Parte 2: Un ejemplo clásico - Factorial ---
 *
 * El factorial de un entero no negativo `n`, denotado por `n!`, es el
 * producto de todos los enteros positivos menores o iguales a `n`.
 * Ejemplo: 5! = 5 * 4 * 3 * 2 * 1 = 120
 *
 * Este problema tiene una definición recursiva natural:
 * - El factorial de 0 es 1. (Caso Base)
 * - El factorial de cualquier otro número `n` es `n` veces el factorial
 * de `n-1`. (Paso Recursivo)
 *
 * Usamos `long long` para el tipo de retorno porque los factoriales
 * ¡crecen muy rápido!
 */
long long factorial(int n)
{
    /* CASO BASE: El factorial de 0 (o 1) es 1. */
    if (n <= 1) {
        return 1;
    }

    /* PASO RECURSIVO: n multiplicado por el factorial del número debajo. */
    return n * factorial(n - 1);
}

/*
 * --- Parte 3: El peligro - Recursión Infinita y Desbordamiento de Pila ---
 *
 * ¿Qué pasa si olvidas el caso base? La función se llamará a sí misma
 * interminablemente. Cada vez que se llama a una función, se utiliza
 * una pequeña cantidad de memoria en la "pila de llamadas" (call stack).
 * Si la recursión nunca se detiene, eventualmente agotará toda la memoria
 * de pila disponible, y el programa fallará con un error llamado
 * DESBORDAMIENTO DE PILA (STACK OVERFLOW).
 */

/*
 * NO DESCOMENTAR Y EJECUTAR ESTA FUNCIÓN.
 * Es un ejemplo de lo que NO se debe hacer.
 */

/*
void infinite_recursion(void)
{
    printf("Esto se ejecutará para siempre... ¡y luego fallará!\n");
    infinite_recursion(); // Sin caso base, sin modificación. ¡Oh, no!
}
*/

int main(void)
{
    printf("--- DEMOSTRACIÓN 1: Cuenta Atrás desde 5 ---\n");
    countdown(5);

    printf("\n--- DEMOSTRACIÓN 2: Calculando Factorial de 10 ---\n");
    int number = 10;
    long long fact_result = factorial(number);
    printf("The factorial of %d is %lld.\n", number, fact_result);

    /* Intentemos otro. */
    number = 15;
    fact_result = factorial(number);
    printf("The factorial of %d is %lld.\n", number, fact_result);

    return 0;
}

/*
 * ====================================================================
 *                            - FIN DE LA LECCIÓN -                
 * ====================================================================
 *
 * Puntos Clave:
 *
 * 1. La recursión es una técnica de resolución de problemas donde una
 *    función se llama a sí misma.
 * 2. Es una alternativa potente a los bucles para problemas que pueden
 *    dividirse en subproblemas más pequeños y auto-similares.
 * 3. Toda función recursiva DEBE tener un CASO BASE para prevenir
 *    la recursión infinita.
 * 4. Toda función recursiva DEBE tener un PASO RECURSIVO que la acerque
 *    al caso base.
 * 5. Olvidar o tener un caso base incorrecto provoca un fallo por
 *    DESBORDAMIENTO DE PILA (STACK OVERFLOW).
 *
 * Aunque los bucles suelen ser más eficientes en C, la recursión puede
 * proporcionar soluciones increíblemente elegantes y legibles para ciertos
 * tipos de problemas, especialmente al tratar con estructuras de datos
 * tipo árbol que veremos más adelante.
 */