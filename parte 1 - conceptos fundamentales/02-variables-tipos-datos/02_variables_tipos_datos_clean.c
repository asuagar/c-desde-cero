// SPDX-License-Identifier: MIT
/**
 * @file 2_variables_tipos_datos.c
 * @brief Lección 2: Variables y Tipos de Datos
 * @author Andrés Suárez <andsuarez@uvigo.es
 * @date 2025-10-06
 *
 * Este archivo introduce los conceptos fundamentales de variables y tipos de datos.
 * Aprendemos cómo almacenar información en memoria y mostrarla en la consola.
 */

#include <stdio.h>

/* Variables y tipos básicos en C */
int main(void)
{
	/* Entero: número sin decimales */
	int player_score = 1250;
	printf("Player score: %d\n", player_score);

	/* Declaración e inicialización en una línea */
	int number_of_lives = 3;
	printf("Number of lives: %d\n", number_of_lives);
	printf("\n");

	/* Doble precisión: números con decimales */
	double item_price = 19.99;
	printf("Price: $%.2f\n", item_price);
	printf("\n");

	/* Carácter individual */
	char player_grade = 'A';
	printf("Grade: %c\n", player_grade);

	/* Imprimir todo junto */
	printf("Summary: %d lives, grade '%c', score %d\n",
	       number_of_lives, player_grade, player_score);

	return 0;
}
