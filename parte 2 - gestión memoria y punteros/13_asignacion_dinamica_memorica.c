/*
 * 13_dynamic_memory_allocation.c - Parte 2, Lección 13: Memoria dinámica
 *
 * Este archivo sirve como lección y demostración sobre asignación dinámica
 * de memoria. Explica los conceptos de pila (STACK) frente a montón (HEAP),
 * e introduce las funciones `malloc()`, `free()` y el operador `sizeof`.
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
 *                           - INICIO LECCIÓN -                           
 * =============================================================================
 *
 * Hasta ahora, el tamaño de nuestras variables y arrays debía conocerse al
 * escribir el programa (TIEMPO DE COMPILACIÓN). Por ejemplo, `int numbers[10];`
 * crea un array que guarda exactamente 10 enteros: ni 9 ni 11.
 *
 * ¿Qué ocurre si no sabemos cuánta memoria necesitaremos hasta que el programa
 * se esté ejecutando? Por ejemplo: preguntar "¿Cuántos estudiantes deseas
 * introducir?" y crear un array del tamaño justo.
 *
 * Aquí entra la ASIGNACIÓN DINÁMICA DE MEMORIA: la capacidad de solicitar
 * memoria al sistema operativo en TIEMPO DE EJECUCIÓN.
 *
 * LA PILA (STACK) Y EL MONTÓN (HEAP)
 * 
 * - Las variables locales (como `int x;` dentro de `main`) se almacenan en la
 *   PILA. Es rápida y su memoria se gestiona automáticamente: al terminar la
 *   función, sus variables se destruyen.
 * 
 * - La memoria dinámica proviene del MONTÓN (HEAP), un área grande y flexible.
 *   Pero hay una condición: TÚ eres responsable de gestionarla. Cuando termines
 *   de usar memoria del HEAP, DEBES devolverla manualmente.
 */

#include <stdio.h>	/* printf, scanf */
#include <stdlib.h>	/* malloc, free */

/*
 * --- Parte 1: `malloc` — Asignación de memoria ---
 *
 * `malloc()` solicita un bloque de memoria del HEAP.
 * 
 * - Recibe un argumento: el número de BYTES a asignar.
 * 
 * - Devuelve un puntero genérico (`void *`) al inicio del bloque.
 *   Ese `void *` se puede convertir al tipo concreto que necesitamos
 *   (p. ej., `int *`, `char *`). En C, el cast no es obligatorio al
 *   asignar a un puntero de tipo específico.
 * 
 * - Si no hay memoria disponible, `malloc()` devuelve NULL. ¡Hay que
 *   comprobarlo SIEMPRE!
 */

/*
 * --- Parte 2: `sizeof` — Tamaño de un tipo ---
 *
 * El tamaño de `int` o de una `struct` puede variar entre plataformas.
 * El operador `sizeof` lo resuelve: `sizeof(int)` devuelve el número de
 * bytes de un entero en el sistema actual. Esto hace el código portable
 * y legible.
 *
 * Patrón habitual con `malloc`:
 *     pointer = malloc(number_of_elements * sizeof(*pointer));
 *     pointer = malloc(n * sizeof(tipo));`
 */

/*
 * --- Parte 3: `free` — Devolver memoria ---
 *
 * Cuando terminas con la memoria asignada con `malloc()`, DEBES liberarla
 * con `free()`. Si no lo haces, creas una FUGA DE MEMORIA (MEMORY LEAK): 
 * el programa retiene memoria que ya no necesita. En programas de 
 * larga duración esto puede agotar la memoria disponible y provocar fallos.
 *
 * `free()` recibe el puntero devuelto por `malloc()`.
 */

int main(void)
{
	int num_students;
	double *gpa_list = NULL;	/* Puntero al array dinámico.
					 * Buena práctica: inicializar a NULL. */

	printf("How many student GPAs do you want to store? ");
	scanf("%d", &num_students);

	/* Evitar tamaños no positivos. */
	if (num_students <= 0) {
		printf("Invalid number of students. Exiting.\n");
		return 1;
	}

	/* --- DEMOSTRACIÓN: ciclo malloc -> uso -> free --- */

	/* 1) ASIGNAR: solicitamos memoria para `num_students` doubles. */
	printf("Allocating memory for %d doubles...\n", num_students);
	gpa_list = malloc((size_t)num_students * sizeof(*gpa_list));

	/* 2) VALIDAR: comprobar si malloc tuvo éxito. */
	if (gpa_list == NULL) {
		printf("Error: Memory allocation failed!\n");
		printf("The OS could not provide the requested memory.\n");
		return 1;
	}
	printf("Memory allocated successfully at address: %p\n\n",
	       (void *)gpa_list);	/* %p requiere (void *). */

	/* 3) USAR: usar `gpa_list` como si fuera un array normal. */
	for (int i = 0; i < num_students; i++) {
		gpa_list[i] = 2.5 + (i * 0.2);	/* Valores de ejemplo. */
	}

	printf("The stored GPAs are:\n");
	for (int i = 0; i < num_students; i++) {
		printf("Student %d GPA: %.2f\n", i + 1, gpa_list[i]);
	}
	printf("\n");

	/* 4) LIBERAR: hemos terminado; devolvemos la memoria al sistema. */
	printf("Freeing the allocated memory...\n");
	free(gpa_list);

	/*
	 * IMPORTANTE: Tras liberar, el puntero `gpa_lista` se convierte en 
	 * PUNTERO COLGANTE (dangling pointer). Apunta a memoria que no ocupa.
	 * Usarlo puede causar errores. Para minimizar riesgos, se reasigna a NULL.
	 * Esto evita su uso accidental.
	 */
	gpa_list = NULL;
	printf("Memory has been released and pointer has been set to NULL.\n");

	return 0;
}

/*
 * =============================================================================
 *                            - FIN DE LA LECCIÓN -                             
 * =============================================================================
 *
 * Puntos clave:
 *
 * 1. La ASIGNACIÓN DINÁMICA solicita memoria del MONTÓN en TIEMPO DE EJECUCIÓN.
 * 2. `malloc()` reserva un bloque de bytes y devuelve un puntero a él.
 * 3. Usa `sizeof` para calcular bytes correctamente y mantener portabilidad.
 * 4. COMPRUEBA si `malloc` devolvió NULL (fallo de asignación).
 * 5. Libera SIEMPRE con `free()` cuando termines. Evita fugas de memoria.
 * 6. Tras `free(ptr)`, establece `ptr = NULL;` para evitar punteros colgantes.
 *
*/
