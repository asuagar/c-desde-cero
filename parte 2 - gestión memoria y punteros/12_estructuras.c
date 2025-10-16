/*
 * 12_structs.c - Parte 2, Lección 12: Structs
 *
 * Este archivo sirve como lección y demostración sobre estructuras (structs).
 * Explica cómo definir y usar tipos de datos personalizados para agrupar
 * variables relacionadas y cómo acceder a sus miembros usando los operadores
 * punto (.) y flecha (->).
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
 *                              - INICIO LECCIÓN -                             
 * =============================================================================
 *
 * Hasta ahora, nuestras variables almacenaban una sola pieza
 * de información (por ejemplo, `int` o `double`), y los arrays contenían varias
 * piezas de información del MISMO tipo.
 *
 * ¿Qué pasa si queremos representar un objeto del mundo real más complejo?
 * Piensa en un/a estudiante: nombre (cadena), ID (entero) y nota (double).
 * Son tipos distintos pero lógicamente pertenecen a la misma entidad.
 *
 * Las ESTRUCTURAS (STRUCT) resuelven esto agrupando variables relacionadas—
 * potencialmente de diferentes tipos—en una unidad lógica única. Una `struct`
 * es un tipo definido por la persona programadora que agrega miembros bajo un
 * mismo "paraguas".
 *
 * En esta lección verás:
 * 1. Cómo DEFINIR un tipo struct (el "plano" de un objeto).
 * 2. Cómo DECLARAR variables de ese tipo struct.
 * 3. Cómo ACCEDER a sus miembros usando el operador PUNTO (.).
 * 4. Cómo usar PUNTEROS a structs y el operador FLECHA (->).
 * 5. Que el operador flecha `p->m` es un atajo conveniente para `(*p).m`.
 */

#include <stdio.h>	/* printf */
#include <string.h>	/* strcpy */

/* --- Parte 1: Definir una struct ---
 *
 * Usamos la palabra clave `struct` para definir la forma de un nuevo tipo.
 * Esta definición todavía no crea variables; solo describe la especificación de
 * "Student". Por convención, las etiquetas de struct suelen escribirse con
 * mayúscula para legibilidad. De esta manera, no se confunde con una variable
 * habitual.
 */
struct Student {
	/* Estos son los MIEMBROS de la struct. */
	char name[50];
	int student_id;
	double gpa;
};

/* --- Parte 2: Punteros a Structs ---
 *
 * Igual que con cualquier otro tipo de dato (`int *`, `char *`), podemos tener
 * punteros a structs. Un puntero a una struct almacena la dirección de memoria
 * de una variable struct.
 *
 * Cuando queremos acceder al miembro de una struct a través de un puntero, no
 * podemos usar directamente el operador punto (.); usamos el OPERADOR FLECHA
 * (->).
 */

int main(void)
{
	/* --- DEMOSTRACIÓN 1: Crear y usar una variable struct --- */
	printf("--- Part 1: Creating and Accessing a Struct ---\n");

	/* Ahora podemos declarar una variable de nuestro nuevo tipo 
	 * `struct Student`. Esto es como construir una casa real 
	 * a partir de su plano o especificación. 
	 */
	struct Student student1;

	/* Para acceder a los miembros de una variable struct, usamos el OPERADOR
	 * PUNTO (.). Asignemos algunos valores a los miembros de student1.
	 * Para cadenas, debemos usar `strcpy` de <string.h> porque no podemos
	 * asignar directamente a un array.
	 */
	strcpy(student1.name, "Jane Doe");
	student1.student_id = 12345;
	student1.gpa = 3.8;

	/* Ahora imprimimos los datos para ver nuestra struct en acción. */
	printf("Student Name: %s\n", student1.name);
	printf("Student ID:   %d\n", student1.student_id);
	printf("Student GPA:  %.2f\n\n", student1.gpa); /* .2f: 2 decimales */

	/* --- DEMOSTRACIÓN 2: Usar un puntero a una struct --- */
	printf("--- Part 2: Pointers to Structs and the Arrow Operator ---\n");

	/* Buena práctica: inicializar punteros. */
	struct Student *p_student = NULL;

	/* Hacemos que el puntero se refiera a `student1`. */
	p_student = &student1;

	/* Ahora, podemos acceder a los elementos de `student1`
	 * a partir del puntero `p_student`. Usamos el OEPRADOR FLECHA (->)
	 * para su lectura o escritura. */
	printf("Accessing data via pointer:\n");
	printf("Name: %s\n", p_student->name);
	printf("ID:   %d\n", p_student->student_id);
	printf("GPA:  %.2f\n\n", p_student->gpa);

	/* También podemos MODIFICAR la struct original a través del puntero. */
	printf("Modifying GPA through the pointer...\n");
	p_student->gpa = 4.0;
	printf("Original student1's new GPA: %.2f\n\n", student1.gpa);

	/* --- La forma larga: desreferencia y operador punto --- */
	/* El operador flecha `->` es "azúcar sintáctico" (un atajo conveniente).
	 * La expresión `p_student->gpa` es exactamente equivalente 
	 * a `(*p_student).gpa`. Esto significa: "primero, DESREFERENCIA el 
	 * puntero para obtener la struct real; luego usa el OPERADOR PUNTO 
	 * sobre esa struct". Los paréntesis son necesarios porque el 
	 * operador punto tiene mayor precedencia que el operador 
	 * de desreferenciación (*).
	 */
	printf("--- Bonus: The Long Way to Access Members via Pointer ---\n");
	printf("Accessing ID with (*p_student).student_id: %d\n",
	       (*p_student).student_id);
	printf("See? It's the same, but `->` is much easier to read and type!\n");

	return 0;
}

/*
 * =============================================================================
 *                              - FIN LECCIÓN -                               
 * =============================================================================
 * 
 * Puntos clave:
 *
 * 1.  Una STRUCT te permite crear tus propios tipos de datos personalizados
 *     agrupando varias variables (members) en una única unidad lógica.
 * 2.  Primero defines el plano (blueprint) de la struct y, después, puedes
 *     declarar variables de ese nuevo tipo.
 * 3.  Usa el OPERADOR PUNTO (`.`) para acceder directamente a los miembros de
 *     una variable struct. Ejemplo: `mi_struct.miembro`
 * 4.  Usa el OPERADOR FLECHA (`->`) para acceder a los miembros de una struct
 *     a través de un puntero. Ejemplo: `mi_puntero_a_struct->miembro`
 * 5.  El operador flecha `p->m` es un atajo conveniente de `(*p).m`.
 *
*/
