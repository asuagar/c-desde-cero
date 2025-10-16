/*
 * 14_file_io.c - Parte 2, Lección 14: Entrada/Salida de ficheros (File I/O)
 *
 * Este archivo sirve como lección y demostración de File I/O (Input/Output).
 * Explica cómo escribir datos en ficheros y cómo leerlos después, permitiendo
 * que los programas guarden y carguen información de forma permanente.
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
 * Hasta ahora, nuestros programas han tenido existencia temporal. Al terminar,
 * cualquier dato en variables, arrays o structs se pierde para siempre.
 *
 * Para que un programa sea realmente útil, necesitamos PERSISTENCIA: guardar
 * datos en un dispositivo de almacenamiento y cargarlos más tarde. Se logra
 * con FILE I/O (Entrada/Salida de ficheros).
 *
 * --- Conceptos básicos de File I/O ---
 *
 * 1. Puntero `FILE`:
 * 
 *    Para trabajar con un fichero en C se usa un puntero especial: `FILE *`.
 *    Es una struct definida en `<stdio.h>` con la información necesaria para
 *    gestionar la conexión con el fichero (ubicación, posición actual, etc.).
 *    No necesitas conocer su contenido; solo usar el puntero.
 *
 * 2. `fopen()` — Abrir un fichero:
 * 
 *    Crea una conexión o “stream” con un fichero del disco. Recibe dos
 *    argumentos: el nombre del fichero y una cadena “modo”. La cadena de texto
 *    puede tener estos valores:
 *    - "w": WRITE. Crea un fichero nuevo. Si existe, se BORRA su contenido.
 *    - "r": READ. Abre un fichero existente para lectura. Si no existe, falla.
 *    - "a": APPEND. Abre para añadir al FINAL. Si no existe, lo crea.
 * 
 *    `fopen()` devuelve `FILE *` en éxito o `NULL` en error. ¡SIEMPRE comprueba
 *    `NULL`!
 *
 * 3. `fclose()` — Cerrar un fichero:
 * 
 *    Paso esencial de limpieza. Finaliza escrituras pendientes y libera
 *    recursos del sistema. Debes cerrar todo fichero que abras.
 *
 * 4. Funciones de escritura y lectura:
 * 
 *    - `fprintf()`: como `printf()`, pero el primer argumento es un `FILE *`.
 *      Escribe texto formateado EN un fichero.
 * 
 *    - `fgets()`: lee una línea de texto DESDE un fichero. Es más segura
 *      porque se indica el tamaño máximo del buffer, evitando desbordamientos.
 */

#include <stdio.h>
#include <stdlib.h>	/* exit() */

int main(void)
{
	/* Un puntero FILE. Inicialízalo siempre a NULL. */
	FILE *file_pointer = NULL;
	/* Nombre del fichero con el que trabajaremos. */
	char *filename = "my_first_file.txt";

	/* --- DEMOSTRACIÓN 1: Escribir en un fichero --- */
	printf("--- Part 1: Writing to a file ---\n");

	/* Paso 1: abrir el fichero en modo ESCRITURA ("w"). */
	file_pointer = fopen(filename, "w");

	/* Paso 2: SIEMPRE comprobar si se abrió correctamente. */
	if (file_pointer == NULL) {
		/* stderr es la salida de error; ideal para mensajes de fallo. */
		fprintf(stderr,
			"Error: Could not open file '%s' for writing.\n",
			filename);
		exit(1);	/* Termina el programa inmediatamente. */
	}

	/* Paso 3: escribir dentro del fichero con fprintf(). */
	printf("Writing data to %s...\n", filename);
	fprintf(file_pointer, "Hello, File!\n");
	fprintf(file_pointer, "This is the second line.\n");
	fprintf(file_pointer, "Player: %s, Score: %d\n", "Max", 100);

	/* Paso 4: cerrar el fichero. */
	fclose(file_pointer);
	/* Buena práctica: anular el puntero tras cerrar. */
	file_pointer = NULL;
	printf("Successfully wrote to and closed the file.\n\n");

	/* --- DEMOSTRACIÓN 2: Leer de un fichero --- */
	printf("--- Part 2: Reading from a file ---\n");

	/* Buffer para almacenar las líneas leídas del fichero. */
	char line_buffer[256];

	/* Paso 1: abrir el mismo fichero en modo LECTURA ("r"). */
	file_pointer = fopen(filename, "r");

	/* Paso 2: comprobar errores de nuevo. El fichero podría haberse borrado 
	 * o podríamos no tener permisos de lectura. */
	if (file_pointer == NULL) {
		fprintf(stderr,
			"Error: Could not open file '%s' for reading.\n",
			filename);
		exit(1);
	}

	/* Paso 3: leer línea a línea con fgets().
	 * Lee hasta encontrar salto de línea, EOF o alcanzar el tamaño
	 * máximo del buffer. Devuelve NULL cuando no queda nada por leer. */
	printf("Reading data from %s:\n", filename);
	while (fgets(line_buffer, sizeof(line_buffer), file_pointer) != NULL) {
		/* Imprimir la línea leída a la consola. */
		printf("%s", line_buffer);
	}

	/* Paso 4: cerrar el fichero. */
	fclose(file_pointer);
	printf("\nSuccessfully read and closed the file.\n");

	return 0;
}

/*
 * =============================================================================
 *                              - FIN LECCIÓN -                                
 * =============================================================================
 *
 * Puntos clave:
 *
 * 1. File I/O permite que los datos del programa sean PERSISTENTES.
 * 2. `FILE *` es el manejador para un fichero abierto.
 * 3. Flujo básico: OPEN -> VALIDATE -> READ/WRITE -> CLOSE.
 * 4. `fopen()` abre con un modo específico ("w", "r", "a"). Debes comprobar
 *    si devuelve `NULL` para manejar errores.
 * 5. `fprintf()` es como `printf()` pero escribe a un stream de fichero.
 * 6. `fgets()` es una forma segura y fiable de leer texto línea a línea.
 * 7. `fclose()` es obligatorio para guardar cambios y liberar recursos.
 *
*/
