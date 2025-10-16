/* 10_punteros.c 

   Este archivo sirve como lección y demostración sobre punteros.
   Explica conceptos clave: direcciones de memoria, declaración de
   punteros, operador de dirección (&) y operador de indirección (*),
   acompañados de un ejemplo ejecutable.

   Fecha: 15-10-2025
   Autores:
     DunamisMax <github.com/dunamismax>
     Andrés Suárez <github.com/asuagar>

   SPDX-License-Identifier: MIT
*/

/* =================================================================
   INICIO LECCIÓN
   =================================================================

   ¡Bienvenido/a a la Parte 2 de tu viaje en C! Ya dominas lo básico;
   ahora profundizamos. Esta lección introduce los PUNTEROS,
   posiblemente la característica más potente y singular
   del lenguaje C.

   Idea central:

   En lugar de almacenar un valor (como 5 o 'c'),
   un PUNTERO almacena una DIRECCIÓN de memoria. Es como tener
   una nota que dice “los datos están allí” en vez de
   sostener los datos directamente.

   ¿POR QUÉ SON IMPORTANTES?

   Permiten código eficiente y son esenciales en temas avanzados:
   memoria dinámica, estructuras de datos (como listas enlazadas)
   y permitir que funciones modifiquen variables originales.

   ¡Dominar punteros es dominar C!
*/

/* --- Parte 1: Variables y sus direcciones de memoria ---

   Cada variable se almacena en algún lugar de la RAM. Cada
   ubicación tiene una DIRECCIÓN única como el número de una casa
   en una calle. El OPERADOR DIRECCIÓN (&) devuelve la dirección
   de una variable.
*/

/* --- Parte 2: ¿Qué es un puntero? ---

   Un PUNTERO es una variable que almacena una DIRECCIÓN de memoria.

   DECLARACIÓN:

   Especifica el tipo al que apuntará, seguido de un asterisco (*),
   y el nombre. Ejemplo: `int *p_number;` declara un puntero para
   la dirección de un `int`.

   Un buen hábito es inicializar los punteros a NULL.
   NULL indica que no apuntan a nada válido. Evita usar
   direcciones basura por accidente.
*/

/* --- Parte 3: Operador de desreferenciación (*) ---

   Una vez definido un puntuero, el asterisco `*` también
   desreferencia y accede al valor almacenado en la dirección
   a la que apunta. Por ello, se llama OPERADOR DESREFERENCIA (*)
*/

#include <stdio.h>  /* se necesita para printf y NULL.  */

int
main (void)
{
  /* --- DEMOSTRACIÓN 1: Obtener la dirección de una variable --- */

  int score = 94;  /* Variable entera con valor y dirección.  */

  printf ("--- Parte 1: Direcciones de variables ---\n");
  printf ("El valor de 'score' es: %d\n", score);

  /* Se usa el operador dirección (&) para obtener su
     dirección. Además, `%p` es un formateador específico
     para imprimir direcciones de memoria en formato hexadecimal.  */
  printf ("La dirección de memoria de 'score' es: %p\n\n", &score);

  /* --- DEMOSTRACIÓN 2: Declarar y usar un puntero --- */

  printf ("--- Parte 2 y 3: Punteros en acción ---\n");

  /* Declaramos un puntero a int e inicializamos a NULL
     por seguridad. Se añade un `p_` para indicar que es
     un puntero.  */
  int *p_score = NULL;
  printf ("Valor inicial p_score (puntero seguro): %p\n", p_score);

  /* Ahora hacemos que el puntero apunte a 'score' asignándole
     su dirección.  */
  p_score = &score;
  printf ("Valor de p_score tras la asignación: %p (la dirección de 'score')\n",
          p_score);

  /* Los punteros también tienen su propia dirección.  */
  printf ("Dirección del propio puntero (p_score): %p\n\n", &p_score);

  /* --- DEMOSTRACIÓN 4: Desreferenciar un puntero --- */

  printf ("--- Parte 4: Desreferenciación ---\n");
  /* Para obtener el valor almacenado en la dirección que
     almacena un puntuero se DESREFERENCIA usando *.  */
  printf ("Valor en la dirección a la que apunta p_score: %d\n\n", *p_score);

  /* --- DEMOSTRACIÓN 5: Modificar una variable mediante su puntero --- */

  printf ("--- Parte 5: Modificar datos vía puntero ---\n");
  printf ("Score original: %d\n", score);

  /* "Vete a la dirección almacenada en el puntero `p_score` y
     escribe allí el valor 100".  */
  printf ("Cambiando el valor a través del puntero...\n");
  *p_score = 100;

  /* Comprobemos que el valor original ha cambiado.  */
  printf ("Nuevo score: %d\n", score);

  return 0;
}

/* ==================================================================
   FIN LECCIÓN
   ==================================================================

   Ideas clave:

   1. Toda variable tiene valor y DIRECCIÓN.
   2. El operador & obtiene la dirección de una variable.
   3. Un PUNTERO almacena una dirección de memoria.
   4. El operador * sobre un puntero accede al valor en esa dirección.
   5. Los punteros permiten leer y modificar variables referenciadas.
   6. Inicializar a NULL es una práctica crítica de seguridad.
*/
