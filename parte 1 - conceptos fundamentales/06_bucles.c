/*
 * 06_bucles.c - Parte 1, Lección 6: Bucles
 *
 * Esta lección introduce los bucles, estructuras de control que permiten
 * ejecutar un bloque de código repetidamente.
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
 *                          - INICIO DE LA LECCIÓN -
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
 * Aquí entran los BUCLES. Un BUCLE es una estructura que repite una secuencia
 * de instrucciones hasta que se cumple una condición específica. Cada ejecución
 * del cuerpo del bucle se llama ITERACIÓN.
 *
 * C tiene tres tipos principales de bucles:
 * 1. El bucle `for`
 * 2. El bucle `while`
 * 3. El bucle `do-while`
 */

#include <stdio.h>

int main(void)
{
	/* --- Parte 1: El bucle `for` --- */

	/*
	 * El bucle `for` es ideal cuando sabes exactamente cuántas veces
	 * quieres repetir un bloque de código. Tiene tres partes separadas
	 * por punto y coma dentro de los paréntesis:
	 *
	 * for (INICIALIZACIÓN; CONDICIÓN; POST-ITERACIÓN) {
	 *	// Código a repetir
	 * }
	 *
	 * 1. INICIALIZACIÓN: se ejecuta una sola vez antes del inicio.
	 * 2. CONDICIÓN: se evalúa antes de cada iteración. Si es falsa,
	 *    el bucle termina.
	 * 3. POST-ITERACIÓN: se ejecuta después de cada ciclo, normalmente
	 *    para modificar el contador (`i++` equivale a `i = i + 1`).
	 */

	printf("--- Parte 1: Bucle 'for' (cuenta regresiva) ---\n");

	/* Ejemplo: cuenta atrás desde 5 hasta 1. */
	for (int i = 5; i > 0; i--) {
		printf("%d...\n", i);
	}
	printf("¡Despegue!\n\n");

	/* --- Parte 2: El bucle `while` --- */

	/*
	 * El bucle `while` repite un bloque de código mientras su condición
	 * sea verdadera. Es útil cuando no sabemos cuántas iteraciones serán
	 * necesarias.
	 *
	 * while (condición) {
	 *	// Código a repetir
	 * }
	 *
	 * IMPORTANTE: algo dentro del bucle debe modificar la condición o se
	 * creará un BUCLE INFINITO.
	 */

	printf("--- Parte 2: Bucle 'while' (menú simple) ---\n");

	int menu_choice = 0;

	while (menu_choice != 4) {
		printf("Menú:\n");
		printf("1. Nuevo juego\n");
		printf("2. Cargar partida\n");
		printf("3. Opciones\n");
		printf("4. Salir\n");
		printf("Introduce tu elección: ");

		scanf("%d", &menu_choice);
		printf("Has elegido: %d\n\n", menu_choice);
	}
	printf("Gracias por jugar.\n\n");

	/* --- Parte 3: El bucle `do-while` --- */

	/*
	 * El bucle `do-while` es una variante del `while`. Evalúa la condición
	 * al final, garantizando que el cuerpo se ejecute al menos una vez.
	 *
	 * Es perfecto para validación de entradas: primero se obtiene el dato,
	 * luego se comprueba si es válido.
	 */

	printf("--- Parte 3: Bucle 'do-while' (validación de entrada) ---\n");

	int secret_number;

	do {
		printf("Introduce un número entre 1 y 10: ");
		scanf("%d", &secret_number);

		if (secret_number < 1 || secret_number > 10)
			printf("Entrada no válida. Intenta de nuevo.\n");

	} while (secret_number < 1 || secret_number > 10);

	printf("Has introducido correctamente el número %d.\n", secret_number);

	return 0;
}

/*
 * =============================================================================
 *                           - FIN DE LA LECCIÓN -
 * =============================================================================
 *
 * En esta lección aprendiste cómo hacer que un programa repita tareas.
 *
 * Puntos clave:
 * - Los bucles ejecutan un bloque de código varias veces.
 * - El bucle `for` se usa cuando el número de repeticiones es conocido.
 * - El bucle `while` depende de una condición que puede cambiar.
 * - El bucle `do-while` siempre se ejecuta al menos una vez.
 *
 * Dominar los bucles es esencial para escribir programas eficientes y claros.
 */
