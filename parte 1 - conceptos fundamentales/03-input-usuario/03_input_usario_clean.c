// SPDX-License-Identifier: MIT
/**
 * @file 3_input_usuario.c
 * @brief Lección 3: Entrada del Usuario
 * @author Andrés Suárez <andsuarez@uvigo.es>
 * @date 2025-10-06
 *
 * @details
 * Esta lección muestra cómo hacer que los programas sean interactivos
 * leyendo la entrada desde el teclado del usuario.
 */

#include <stdio.h>

/* Entrada del usuario con scanf */
int main(void)
{
	int user_age;
	printf("Enter your age: ");
	scanf("%d", &user_age);
	printf("Age: %d\n\n", user_age);

	double user_gpa;
	printf("Enter your GPA: ");
	scanf("%lf", &user_gpa);
	printf("GPA: %.2f\n\n", user_gpa);

	char favorite_letter;
	printf("Enter your favorite letter: ");
	scanf(" %c", &favorite_letter);
	printf("Letter: '%c'\n", favorite_letter);

	return 0;
}
