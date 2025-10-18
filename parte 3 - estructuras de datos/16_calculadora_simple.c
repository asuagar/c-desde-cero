/*
 * 16_calculadora_simple.c - Parte 3, Lección 16: Calculadora simple
 *
 * Este archivo es nuestro primer PROYECTO. Combina varios conceptos
 * que hemos aprendido: uso de argumentos de línea de comandos,
 * conversión de tipos y estructuras condicionales para construir una
 * calculadora simple ejecutable desde la consola.
 *
 * Fecha: 17-10-2025
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
 * Es momento de comenzar a escribir programas. Este lección es
 * el primer PROYECTO REAL: una calculadora sencilla que funciona
 * desde la línea de comandos.
 * 
 * Objetivo:
 * 
 * Crear una calculadora básica que se ejecute desde la línea de comandos.
 * Ejemplo de uso: ./16_simple_calculator 10 + 5
 * Resultado esperado: 10.00 + 5.00 = 15.00
 *
 * Conceptos:
 * 
 * 1. Argumentos de línea de comandos (`argc`, `argv`) para 
 *    definir los números y la operación.
 * 
 * 2. Conversión de cadenas a números con `atof()`. Los argumentos
 *    en `argv` son cadenas de texto. Es necesario convertirlos 
 *    a tipos numéricos para poder operar con ellos.
 * 
 * 3. Estructuras condicionales (`if`, `switch`) para comprobar
 *    si el usuario introdujo el inputo correcto y dedicir la
 *    operación matemáica.
 * 
 * 4. Manejo de errores. Se producirá un mensaje si el usuario
 *    hace un error e introduce errores matemáticos como la división
 *    entre cero.
 */

#include <stdio.h>
#include <stdlib.h> /* atof() y exit()*/
#include <string.h> /* strcmp()*/

int main(int argc, char *argv[]) 
{
    double num1, num2, result;
    char operator;

    /* --- Paso 1: Validar número de argumentos 
     * Se necesitan 4 argumentos:
     * argv[0]: nombre programa
     * argv[1]: primer número
     * argv[2]: operador
     * argv[3]: segundo número
     */
    if (argc != 4) {
	/* Si no hay 4 argumentos, se produce mensaje de error*/
        fprintf(stderr, "Uso: %s <num1> <operador> <num2>\n", argv[0]);
        fprintf(stderr, "Ejemplo: %s 12.5 / 2\n", argv[0]);
        exit(1);
    }

    /* --- Paso 2: Convertir y almacenar argumetnos --- 
     * `atof` (ASCII to float) convierte una cadena a un double.
     */
    num1 = atof(argv[1]);
    num2 = atof(argv[3]);

    /* El operador es una cadena como "+". Se necesita solamente 
     * su primer elemento. Se comprueba si la cadena tiene más
     * de un elemento, en cuyo caso sería inválido.
     */
    if (strlen(argv[2]) != 1) {
        fprintf(stderr, "Error: operador inválido '%s'.\n", argv[2]);
        fprintf(stderr, "Debe ser un solo carácter (+, -, *, /).\n");
        exit(1);
    }

    operator = argv[2][0];

    /* --- Paso 3: Hacer el cálculo --- 
     * Un `switch` es una instrucción usada para comprobar una condición
     * y tomar una acción. En este caso, se comprueba el operador y se
     * decide la operación matemática.
     */
    switch (operator) {
    case '+':
        result = num1 + num2;
	/* `break` sale del switch. Es obligatorio usarlo.
	 * De no usarse, se continuaría dentro del switch.
	 * Se podría ejecutar otra parte, si se diese el caso.
	 */
        break; 
    case '-':
        result = num1 - num2;
        break;
    case '*':
	/* Algunos terminales de línea de comando pueden interpretar
	 * el * como un comodín. Por ello, es aconsejable escribir
	 * '*' para procesarse correctamente.
	 */
        result = num1 * num2;
        break;
    case '/':
	/* Este es un caso IMPORTANTE. No se puede dividir por cero. */
        if (num2 == 0) {
            fprintf(stderr, "Error: división entre cero.\n");
            exit(1);
        }
        result = num1 / num2;
        break;
    default:
	/* Si el operador no es uno de los anteriores, 
	 *es incorrecto. 
	 */
        fprintf(stderr, "Error: operador desconocido '%c'.\n", operator);
        fprintf(stderr, "Operadores válidos: +, -, *, /\n");
        exit(1);
    }

    /* --- Paso 4: Mostrar resultado --- 
    * Si el programa llega así, se ha realizado al operación con éxito.
    * Se usa %.2f para formatear los números decimales con dos cifras 
    * únicamente. Esto produce un resultado más limpio.
    */
    printf("%.2f %c %.2f = %.2f\n", num1, operator, num2, result);
    return 0;
}

/*
 * =============================================================================
 *                          - FIN DE LA LECCIÓN -
 * =============================================================================
 *
 * En esta práctica has aprendido a:
 * 
 * - Usar `argc` y `argv` para aplicaciones raeles.
 * - Convertir texto a números reales para su manejo.
 * - Detectar y manejar errores de usuario.
 *
 * Compilación y ejecución:
 * 
 * gcc -Wall -Wextra -std=c11 -o calculadora 16_calculadora_simple.c
 *
 * Ejemplos:
 *     ./calculadora 5 + 3
 *     ./calculadora 10 / 0
 *     ./calculadora 20 '*' 4
 */
