/*
 * 15_command_line_arguments.c - Parte 2, Lección 15: Argumentos de línea
 *                               de comandos
 *
 * Este archivo sirve como lección y demostración del uso de argumentos de
 * línea de comandos. Explica parámetros especiales de `main` que permite a un
 * programa recibir y procesar entradas directamente desde la línea de comandos
 * cuando se ejecuta.
 *
 * Fecha: 15-10-2025
 * Autores:
 *   DunamisMax <github.com/dunamismax>
 *   Andrés Suárez <github.com/asuagar>
 *
 * SPDX-License-Identifier: MIT
 */

/*
 * =============================================================================
 *                             - INICIO LECCIÓN -                               
 * =============================================================================
 *
 * Ya has estado usando argumentos de línea de comandos sin darte cuenta.
 * Cuando compilas un programa así:  `gcc -o my_program my_program.c`
 *
 * Las cadenas `-o`, `my_program` y `my_program.c` son argumentos de línea de
 * comandos pasados al programa `gcc`. Le indican a `gcc` qué hacer. Esto hace 
 * que tus programas sean flexibles. En vez de pedir datos con `scanf`, 
 * puedes hacer que la persona usuaria los pase al ejecutar el programa.
 *
 * Para acceder a estos argumentos, usamos parámetros especiales e `main`.
 *
 * 			`int main(int argc, char *argv[])`
 *
 * Desglose:
 *
 * 1. `int argc`:
 *    `argc` significa “argument count”. Es el número de argumentos de línea de
 *    comandos que se pasaron a tu programa. Este conteo SIEMPRE incluye el
 *    nombre del propio programa como primer argumento. Por tanto, `argc` es
 *    al menos 1.
 *
 * 2. `char *argv[]`:
 *    `argv` significa “argument vector”. Es un VECTOR DE CADENAS donde cada
 *    elemento es uno de los argumentos de la línea de comandos.
 *
 *    - `argv[0]` siempre es el nombre del ejecutable.
 *    - `argv[1]` es el primer argumento tecleado por la persona usuaria.
 *    - `argv[2]` es el segundo, y así sucesivamente.
 *    - `argv[argc - 1]` es el último argumento.
 *    - El estándar de C define que `argv[argc]` será un puntero `NULL`.
 */

#include <stdio.h>
#include <stdlib.h>	/* atoi: convertir cadena a entero */

/* Nota la nueva firma de main. */
int main(int argc, char *argv[])
{
	/* --- DEMOSTRACIÓN 1: Imprimir todos los argumentos --- */
	printf("--- Part 1: Inspecting argc and argv ---\n");

	/* Primero, veamos qué contiene `argc`. */
	printf("Argument count (argc): %d\n", argc);

	/* Ahora recorremos `argv` e imprimimos cada argumento. */
	printf("Arguments (argv):\n");
	for (int i = 0; i < argc; i++)
		printf("  argv[%d]: \"%s\"\n", i, argv[i]);
	printf("\n");

	/* --- DEMOSTRACIÓN 2: Usar los argumentos --- */
	printf("--- Part 2: A Practical Example ---\n");

	/*
	 * Comprobación típica: verificar que se proporcionó el número correcto
	 * de argumentos. Haremos un programa sencillo que espera nombre y edad.
	 *
	 * Esperamos 3 argumentos:
	 * 1. Nombre del programa (p. ej., ./15_argumentos_linea_comandos)
	 * 2. Un nombre (p. ej., "Alice")
	 * 3. Una edad (p. ej., "30")
	 */
	if (argc != 3) {
		/* Si el conteo es incorrecto, imprime “usage” en stderr. 
		 * Esta es una práctica habitual cuando se trabaja con 
		 * línea de comandos. */
		fprintf(stderr, "Usage: %s <name> <age>\n", argv[0]);
		fprintf(stderr, "Example: %s Alice 30\n", argv[0]);
		return 1;	/* 1 indica error. */
	}

	/* Si llegamos aquí, el conteo es correcto. 
	 * `argv[1]` ya es cadena: el nombre. */
	char *name = argv[1];

	/* `argv[2]` es la edad, pero como CADENA (p. ej., "30").
	 * Convertimos a entero con `atoi()` (ASCII to Integer).  */
	int age = atoi(argv[2]);

	printf("Hello, %s!\n", name);
	printf("You are %d years old.\n", age);
	printf("In 10 years, you will be %d.\n", age + 10);

	return 0;	
}

/*
 * =============================================================================
 *                              - FIN LECCIÓN -                                 
 * =============================================================================
 *
 * Puntos clave:
 *
 * 1.  Los argumentos de línea de comandos hacen tus programas potentes y
 *     “scriptables”.
 * 2.  Usa `int main(int argc, char *argv[])` para aceptar argumentos.
 * 3.  `argc` es el conteo total, incluido el nombre del programa.
 * 4.  `argv` es un array de cadenas con los argumentos reales.
 * 5.  `argv[0]` siempre es el nombre del programa.
 * 6.  Comprueba `argc` antes de acceder a `argv` para validar entradas.
 * 7.  Los argumentos llegan como cadenas. Convierte a números con funciones
 *     como `atoi()` (enteros) o `atof()` (reales).
 *
 */
