// SPDX-License-Identifier: MIT
/**
 * @file 08_vectores.c
 * @brief Parte 1, Lección 8: Vectores (Arrays)
 * @details
 * Esta lección introduce los vectores, una estructura de datos
 * fundamental para almacenar colecciones de elementos del mismo tipo.
 * 
 * @date 10-15-2025
 * @author DunamisMax <github.com/dunamismax>
 * @author Andrés Suárez <github.com/asuagar>
 * SPDX-License-Identifier: MIT
 */

/*
 * =============================================================================
 *                            - INICIO DE LA LECCIÓN -                         
 * =============================================================================
 *
 * Hasta ahora, hemos usado variables que solo almacenan un valor 
 * a la vez. Por ejemplo: `int score = 100;`.Pero ¿qué ocurre si
 * queremos guardar las notas de una clase de 30 alumnos? 
 * Declarar 30 variables diferentes (`score1`, `score2`, etc.) sería ineficiente.
 *
 * Un VECTOR es una estructura que almacena una colección de
 * elementos del * MISMO tipo y de tamaño fijo. Imagina una fila 
 * de cajas numeradas, donde cada caja contiene un valor del 
 * mismo tipo.
 */

#include <stdio.h>

int main(void) {
    // --- Parte 1: Declaración e inicialización de un vector ---

    /*
     * Para declarar un vector se especifica:
     * - el tipo de datos de sus elementos,
     * - el nombre del vector ,
     * - el número de elementos (tamaño) entre corchetes `[]`.
     *
     * Ejemplo: un vector `high_scores` que puede almacenar 
     * 5 enteros.
     */

    int high_scores[5];    /* vector de 5 enteros. */

    /*
     * ACCESO A ELEMENTOS:
     * Se accede a cada elemento usando un ÍNDICE entre 
     * corchetes. C usa INDEXAZACIÓN DESDE CERO (ZERO-BASED 
     * INDEXING): el primer elemento está en el índice 0,
     * el segundo en 1, y así sucesivamente. Para un vector 
     * de tamaño 5, los índices válidos son 0, 1, 2, 3 y 4.
     *
     * Acceder a un índice fuera de ese rango (por ejemplo, `high_scores[5]`) produce COMPORTAMIENTO INDEFINIDO, 
     * causa común de errores y fallos.
     */

    printf("--- Parte 1: Asignación y acceso a elementos ---\n");
    high_scores[0] = 980; // asigna 980 al primer elemento
    high_scores[1] = 950; // asigna 950 al segundo elemento
    high_scores[2] = 875;
    high_scores[3] = 820;
    high_scores[4] = 799; // asignación al quinto (y último) elemento

    printf("La puntuación más alta es: %d\n", high_scores[0]);
    printf("La tercera puntuación más alta es: %d\n", high_scores[2]);
    printf("\n");

    // --- Parte 2: Listas de inicialización ---

    /*
     * Asignar valores uno por uno puede ser tedioso.
     * También se puede inicializar un vector al declararlo,
     * usando una lista entre llaves `{}`.
     *
     * Si se proporciona una lista de inicialización, el compilador
     * puede deducir automáticamente el tamaño dejando los corchetes vacíos.
     */

    printf("--- Parte 2: Uso de listas de inicialización ---\n");
    double temperatures[] = {72.5, 75.0, 69.8, 80.1, 85.3};
    char grades[] = {'A', 'B', 'A', 'C', 'B', 'A'};

    printf("La primera temperatura registrada fue: %.1f\n", temperatures[0]);
    printf("La calificación del cuarto alumno fue: %c\n", grades[3]);
    printf("\n");

    // --- Parte 3: Recorrido de un vector ---

    /*
     * El verdadero poder de los vectores se aprecia al combinarlos
     * con bucles. Un bucle `for` es ideal para recorrer un vector 
     * realizar acciones sobre cada elemento.
     */

    printf("--- Parte 3: Recorrido con un bucle 'for' ---\n");
    printf("Todas las temperaturas registradas:\n");

    /*
     * Haremos un bucle desde 0 hasta el último elemento, sin 
     * incluirlo. El contador del bucle `i` se usa como índice
     * del vector.
     */

    for (int i = 0; i < 5; i++) {
        printf("  Día %d: %.1f\n", i + 1, temperatures[i]);
    }
    printf("\n");

    /*
     * También podemos usar un bucle para calcular un valor agregado,
     * como la suma de todas las puntuaciones.
     */

    int total_score = 0;
    for (int i = 0; i < 5; i++) {
        total_score = total_score + high_scores[i];
    }
    printf("Suma de todas las puntuaciones: %d\n", total_score);

    return 0;
}

/*
 * =============================================================================
 *                               - FIN DE LA LECCIÓN -                        
 * =============================================================================
 *
 * En esta lección aprendiste a manejar colecciones de datos.
 *
 * Puntos clave:
 * - Un VECTOR es una colección de tamaño fijo con elementos del mismo tipo.
 * - Los índices comienzan en 0.
 * - Para acceder a un elemento se usa `nombre[indice]`.
 * - Se pueden inicializar con listas de valores: `int arr[] = {1, 2, 3};`.
 * - Los bucles son esenciales para recorrerlos.
 *
 * Nota: En este ejemplo usamos valores fijos (por ejemplo, `i < 5`).
 * Más adelante aprenderás formas más seguras de manejar tamaños de 
 * vectores.
 * 
 */
