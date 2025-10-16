/*
 * 04_operadores_basicos.c - Parte 1, Lección 4: Operadores básicos
 *
 * Esta lección explica los operadores fundamentales en C
 * usados para cálculos y comparaciones.
 *
 * Fecha: 2025-10-08
 * Autores:
 *   DunamisMax <github.com/dunamismax>
 *   Andrés Suárez <github.com/asuagar>
 *
 * SPDX-License-Identifier: MIT
 */

/*
 * =============================================================================
 *                       - INICIO DE LA LECCIÓN -
 * =============================================================================
 *
 * En programación, un OPERADOR es un símbolo especial que realiza una operación
 * sobre uno o más valores o variables (llamados OPERANDOS). Por ejemplo, en
 * `5 + 3`, el `+` es el operador y `5` y `3` son los operandos.
 *
 * En esta lección veremos tres categorías principales de operadores:
 * 1. Operadores aritméticos: para realizar cálculos matemáticos.
 * 2. Operadores relacionales: para comparar valores.
 * 3. Operadores lógicos: para combinar comparaciones múltiples.
 */

#include <stdio.h>

int main(void)
{
	/* Declaramos algunas variables con las que trabajar. */
	int a = 10;
	int b = 3;

	/* --- Parte 1: Operadores aritméticos --- */
	printf("--- Parte 1: Operadores aritméticos ---\n");
	printf("Valores iniciales: a = %d, b = %d\n\n", a, b);

	/* `+` (Suma) */
	printf("a + b = %d\n", a + b);

	/* `-` (Resta) */
	printf("a - b = %d\n", a - b);

	/* `*` (Multiplicación) */
	printf("a * b = %d\n", a * b);

	/*
	 * `/` (División) — ¡Cuidado!
	 * Cuando divides dos enteros en C, el resultado también es un entero.
	 * La parte fraccionaria se descarta (truncada). Esto se llama
	 * DIVISIÓN ENTERA.
	 */
	printf("División entera (a / b) = %d\n", a / b);

	/*
	 * Para obtener un resultado decimal, al menos uno de los operandos
	 * debe ser de tipo flotante (por ejemplo, `double`).
	 * Podemos lograrlo haciendo un “casting” de uno de los enteros.
	 */
	double precise_division = (double)a / b;
	printf("División en coma flotante ((double)a / b) = %f\n",
	       precise_division);

	/*
	 * `%` (Módulo)
	 * Este operador devuelve el RESTO de una división entera.
	 * Es muy útil en muchas situaciones.
	 */
	printf("Módulo (a %% b) = %d\n", a % b);
	printf("\n");

	/* --- Parte 2: Operadores relacionales --- */
	/*
	 * Los OPERADORES RELACIONALES se usan para comparar dos valores.
	 * El resultado de una comparación es un valor lógico.
	 * En C, no existe un tipo booleano incorporado; en su lugar:
	 * - `0` representa FALSO.
	 * - Cualquier número distinto de 0 representa VERDADERO (normalmente 1).
	 */
	printf("--- Parte 2: Operadores relacionales ---\n");
	printf("Los resultados serán 1 para VERDADERO y 0 para FALSO.\n\n");

	/* `==` (Igual a) — MUY IMPORTANTE */
	printf("¿a == 10? %d\n", a == 10);
	printf("¿a == b?  %d\n", a == b);

	/* `!=` (Distinto de) */
	printf("¿a != b?  %d\n", a != b);

	/* `>` (Mayor que) */
	printf("¿a > b?   %d\n", a > b);

	/* `<` (Menor que) */
	printf("¿a < b?   %d\n", a < b);

	/* `>=` (Mayor o igual que) */
	printf("¿a >= 10? %d\n", a >= 10);

	/* `<=` (Menor o igual que) */
	printf("¿b <= 3?  %d\n", b <= 3);
	printf("\n");

	/* --- Parte 3: Operadores lógicos --- */
	/*
	 * Los OPERADORES LÓGICOS se utilizan para combinar o modificar
	 * expresiones lógicas (verdaderas o falsas).
	 */
	printf("--- Parte 3: Operadores lógicos ---\n");

	int is_player_alive = 1;
	int has_key = 0;
	printf("Jugador vivo: %d, Jugador tiene llave: %d\n\n",
	       is_player_alive, has_key);

	/* `&&` (Y lógico) */
	printf("¿Puede abrir puerta (is_player_alive && has_key)? %d\n",
	       is_player_alive && has_key);

	/* `||` (O lógico) */
	printf("¿Jugador vivo O tiene llave? %d\n",
	       is_player_alive || has_key);

	/* `!` (NO lógico) */
	printf("El opuesto de has_key (!has_key) es: %d\n", !has_key);
	printf("\n");

	/* --- Parte 4: Precedencia de operadores --- */
	printf("--- Parte 4: Precedencia de operadores ---\n");
	/*
	 * Igual que en matemáticas, los operadores en C tienen un orden de
	 * evaluación predeterminado llamado PRECEDENCIA DE OPERADORES.
	 * Por ejemplo, `*` y `/` se evalúan antes que `+` y `-`.
	 */
	int result1 = 5 + 2 * 10;
	printf("5 + 2 * 10 = %d\n", result1);

	/*
	 * Puedes usar paréntesis `()` para forzar un orden específico.
	 * Es buena práctica usarlos para hacer el código más claro.
	 */
	int result2 = (5 + 2) * 10;
	printf("(5 + 2) * 10 = %d\n", result2);

	return 0;
}

/*
 * =============================================================================
 *                           - FIN DE LA LECCIÓN -
 * =============================================================================
 *
 * En esta lección aprendiste sobre los operadores fundamentales en C:
 * - Aritméticos (+, -, *, /, %) para cálculos.
 * - Relacionales (==, !=, >, <, >=, <=) para comparaciones.
 * - Lógicos (&&, ||, !) para combinar condiciones.
 *
 * También viste la división entera, el operador módulo y cómo
 * usar paréntesis `()` para controlar el orden de las operaciones.
 */
