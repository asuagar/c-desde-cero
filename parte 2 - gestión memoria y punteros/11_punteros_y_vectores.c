/* 11_punteros_y_vectores.c 

   Esta lección explica la relación entre punteros y arrays: cómo el
   nombre del array se usa como dirección del primer elemento y cómo
   aplicar ARITMÉTICA DE PUNTEROS de forma segura.

   Fecha: 15-10-2025
   Autores:
     DunamisMax <github.com/dunamismax>
     Andrés Suárez <github.com/asuagar>

   SPDX-License-Identifier: MIT
*/

/* =================================================================
   INICIO DE LA LECCIÓN
   =================================================================

   En la lección anterior, vimos que un PUNTERO almacena una
   dirección de memoria.  Aquí exploramos una de las relaciones
   más importantes del lenguaje C: la conexión entre punteros y
   vectores.

   LA GRAN REVELACIÓN:

   El nombre de un vector es el puntero de su primer elemento.
   Esto significa que el nombre de un vector es una dirección
   de memoria.  Por eso, no hace falta un operador `&` cuando se
   usa `scanf` con una cadena.  ¡El propio nombre de la cadena
   proporciona la dirección de memoria!

   Esta relación habilita la ARITMÉTICA DE PUNTEROS: movernos entre
   elementos de un vector sumando un desplazamiento en unidades del
   tipo de dato apuntado.
*/

#include <stdio.h>

int
main (void)
{
  /* Vamos a crear un vector de números enteros.
     En memoria, estos valores se almacenan de forma contigua.
     Es decir, cada elemento se escribe en direcciones consecutivas.
     Así se crea una memoria contigua.  */
  int grades[] = {85, 92, 78, 99, 67};
  int count = 5;  /* Número de elementos en el array.  */

  /* --- Parte 1: El nombre de un vector es un puntero --- */

  printf ("--- Part 1: El nombre de un vector es un puntero ---\n");

  /* Vamos a demostrar que el nombre del vector `grades`
     se trata de una dirección.  Para ello, imprimimos el
     valor de `grades` y la dirección de su primer elemento.  */
  printf ("Value of 'grades' (the array name): %p\n", grades);
  printf ("Address of the first element (&grades[0]): %p\n", &grades[0]);
  printf ("They are the same!\n\n");

  /* --- Parte 2: Aritmética de punteros --- */

  printf ("--- Part 2: Aritmética de Punteros ---\n");

  /* Puesto que el nombre de un vector es un puntero,
     se puede asignar directamente a otro puntero sin usar `&`.  */
  int *p_grades = grades;

  /* Acceso al primer elemento por índice y por desreferencia.  */
  printf ("First element using grades[0]: %d\n", grades[0]);
  printf ("First element using *p_grades: %d\n\n", *p_grades);

  /* Ahora vamos a por la magia.  ¿Qué sucede cuando se le suma 1
     a un puntero?  La ARITMÉTICA DE PUNTEROS es inteligente.
     Al sumar 1 a un puntero tipo int, mueve una unidad la dirección.
     La unidad es el tamaño de UN ELEMENTO del vector.
     Eso quiere decir que el puntero se mueve `sizeof(int)` bytes.
     En resumen, `*(p_grades + 1)` significa "vete a la dirección
     del primer elemento del vector, muévela un tamaño igual
     al tipo `int` y finalmente haz una desreferencia".  */

  printf ("Second element using grades[1]: %d\n", grades[1]);
  printf ("Second element using *(p_grades + 1): %d\n\n", *(p_grades + 1));

  printf ("Third element using grades[2]: %d\n", grades[2]);
  printf ("Third element using *(p_grades + 2): %d\n\n", *(p_grades + 2));

  /* --- Parte 3: Equivalencia p[i] y *(p + i) --- */

  printf ("--- Part 3: Equivalencia de p[i] y *(p + i) ---\n");

  /* El lenguaje C garantiza que para un vector p y un índice i,
     la expresión p[i] es LO MISMO que *(p + i).  La notación con
     los corchetes [] es más breve y fácil de usar.  A esto se
     le llama "azúcar sintáctico" y hace la aritmética de
     punteros más amigable.  */
  printf ("Accessing the fourth element (index 3):\n");
  printf ("Using array notation grades[3]: %d\n", grades[3]);
  printf ("Using pointer notation *(grades + 3): %d\n\n", *(grades + 3));

  /* Esto también se cumple para el puntero `p_grades`.  */
  printf ("Accessing the fifth element (index 4) via our pointer variable:\n");
  printf ("Using pointer notation *(p_grades + 4): %d\n", *(p_grades + 4));
  printf ("Using array notation p_grades[4]: %d\n\n", p_grades[4]);

  /* --- Parte 4: Recorrer un vector con un puntero --- */

  printf ("--- Part 4: Recorrer un vector con un puntero ---\n");
  printf ("Grades: ");
  for (int i = 0; i < count; i++)
    {
      /* Uso de aritmética de punteros para cada elemento.  */
      printf ("%d ", *(grades + i));
    }
  printf ("\n");

  return 0;
}

/* ==================================================================
   FIN DE LA LECCIÓN
   ==================================================================

   Ideas clave:
   1. El nombre de un array es un puntero a su primer elemento.
   2. `array` y `&array[0]` apuntan a la misma dirección.
   3. Sumar n a un puntero avanza n * sizeof(tipo) bytes.
   4. La notación `p[i]` es azúcar sintáctico de `*(p + i)`.
   5. Esta relación hace eficiente usar un vector como argumento de
      una función.  La función no hace una copia local del vector,
      sino que trabaja directamente con las direcciones de memoria.
*/
