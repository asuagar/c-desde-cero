/*
 * 18_function_pointers.c - Parte 3, Lección 18: Punteros a función
 *
 * Esta lección explica el concepto de punteros a función en C. Muestra cómo
 * almacenar direcciones de funciones, pasarlas como argumentos y usarlas para
 * construir programas más flexibles y modulares.
 *
 * Fecha: 15-06-2025
 * Autores:
 *   DunamisMax <github.com/dunamismax>
 *   Andrés Suárez <github.com/asuagar>
 *
 * SPDX-License-Identifier: MIT
 */

/*
 * =============================================================================
 *                         - INICIO DE LA LECCIÓN -
 * =============================================================================
 *
 * Hasta ahora, hemos trabajado con punteros a datos como `int` o 
 * `struct` los cuales almacen la dirección de memoria de la variable.
 * Pero C lleva el proceso un paso más allá: es posible hacer
 * punteros a funciones. Un puntero a función guarda la dirección 
 * en memoria de una función y puede usarse para invocarla
 * indirectamente.
 * 
 * Esto puede parecer extraño, pero es una técnica poderosa. Facilita 
 * tratar otra función comos si fuese una variable y permite:
 *
 * - pasar funciones como parámetros a otras funciones.
 * - almacenar funciones dentro de vectores.
 * - cambiar la función llamada durante la ejecución del programa.
 *
 * El uso más común es el mecanismo de respuesta o CALLBACK donde
 * se especifica una función genérica y una función auxiliar.
 * La función genérica llama a la función auxiliar meidante el puntero
 * para completar sus tareas.
 *
 * Sintaxis general:
 * tipo_retorno (*nombre_puntero)(tipos_parametros);
 *
 * Ejemplo:
 * int (*operation)(int, int);
 * operation = suma;
 * result = operation(2, 3);
 *
 * ¡Llamar a través de un puntero a función se comporta igual que una llamada
 * directa!
 */

#include <stdio.h>

/* --- Parte 1: Funciones matemáticas de ejemplo --- 
 * Vamos a definir dos funciones simples. Es requisito que ambas
 * tengan la misma FIRMA (SIGNATURE). Por firma, se entiende 
 * los tipos de los parámetros y del retorno.
 */
int add(int a, int b) 
{
    return a + b;
}

int subtract(int a, int b) 
{
    return a - b;
}

int multiply(int a, int b) 
{
    return a * b;
}

int divide(int a, int b) 
{
    if (b == 0) {
        printf("Error: division by zero.\n");
        return 0;
    }
    return a / b;
}

/* --- Parte 2: La función callback ---
 * Aquí se define la función genérica que toma dos números y el
 * puntero a función como argumentos. Usará la función apuntada
 * para realizar el cálculo. El tercer parámetro 
 * `int (*operation_func)(int,int)`es el puntero a una función
 * auxiliar. Se traduce como "Declaro la dirección de un función 
 * que toma dos enteros y devuelve un entero".
 */
void perform_calculation(int x, int y, int (*operation_func)(int, int))
{
    /* Primero, comprueba si el puntero es válido (not NULL) */
    if (operation_func == NULL)
    {
        printf("Error: No operation function provided.\n");
        return;
    }
    /* LLama la función auxiliar mediante el puntero*/ 
    int result = operation_func(x, y); 
    printf("Performing calculation... Result is: %d\n", result);
}

int main(void) 
{
    /* --- DEMOSTRACIÓN 1: Declaración y uso de un puntero a función --- */
    printf("--- Parte 1: Uso básico de punteros a funciones ---\n");

    /*
     * Esta es la sintaxis para declarar un puntero a función.
     * Debe coincidir con la firma de las funciones a las que apuntará.
     * tipo_retorno (*nombre_puntero)(tipos_parámetros);
     */
    int (*p_calculate)(int, int) = NULL;

    /*
     * Los paréntesis alrededor de `*p_calculate` son ESENCIALES.
     * Sin ellos, `int *p_calculate(int, int);` declararía una
     * función llamada `p_calculate` que devuelve un `int*`.
     */
    p_calculate = add; /* También se puede usar `&add`, pero no es necesario. */

    /* LLAMADA: Invoca la función a través del puntero. */
    int sum = p_calculate(10, 5);
    printf("Llamada mediante puntero (add): %d\n", sum);

    /* Ahora, apunta el MISMO puntero a una función DIFERENTE. */
    p_calculate = subtract;

    /* Y la invoca de nuevo. El puntero ahora ejecuta un código diferente. */
    int difference = p_calculate(10, 5);
    printf("Llamada mediante puntero (subtract): %d\n\n", difference);

    /* --- DEMOSTRACIÓN 2: Uso de punteros a funciones como callbacks --- */
    printf("--- Parte 2: Callbacks en acción ---\n");

    int a = 20, b = 12;

    /*
     * Aquí llamamos a `perform_calculation` y pasamos la función `add`
     * como callback. `perform_calculation` invocará a `add`.
     */
    printf("Pasando la función 'add' como callback:\n");
    perform_calculation(a, b, add);

    /*
     * Ahora llamamos a la misma función genérica, pero le pasamos una
     * herramienta diferente para trabajar.
     */
    printf("Pasando la función 'subtract' como callback:\n");
    perform_calculation(a, b, subtract);

    return 0;
}

/*
 * =============================================================================
 *                           - FIN DE LA LECCIÓN -
 * =============================================================================
 *
 * Conceptos clave:
 * 
 * - Un PUNTERO A FUNCIÓN almacena la dirección de una función.
 * - La sintaxis es crítica `return_type (*poninter_name) params`
 * - Permite un código altamente flexible gracias a funciones de 
 *   respuesta (CALLBACKS)
 * - Un callback se produce cuando se pasa una función (A) como 
 *   argumento de otra función (B), y B llama a A para realizar
 *   parte de la tarea.
 * 
 * Se trata de un tema avanzado. Dominarlo abre la puerta a la 
 * creación de código modular y altamente reusable.
 *
 * Prueba a elegir diferentes operaciones y observa cómo las llamadas
 * se dirigen a distintas funciones sin modificar el flujo principal.
 */
