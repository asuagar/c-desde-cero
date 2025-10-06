// SPDX-License-Identifier: MIT
/**
 * @file 1_hola_mundo_full.c
 * @brief Lección 1: Hello word!
 * @author Andrés Suárez <andsuarez@uvigo.es>
 * @date 2025-10-06
 * 
 * Este archivo contiene tu primer programa en C y tu primera lección.
 * La enseñanza se realiza a través de los comentarios del archivo. Léelos
 * de arriba hacia abajo para entender lo que ocurre.
 */

 /* ============================================================================
 *                              - INICIO LECCIÓN -                             
 * =============================================================================
 *
 * ¿QUÉ ES UN COMPILADOR?
 * 
 * Un compilador es un programa que traduce el código C, entendible por humano,
 * a código máquina que una computadora puede ejecutar. Para este curso, 
 * se usará GCC (GNU Compiler Collection).
 */

// --- Parte 1: Directivas del preprocesador ---
 
/* `#include` es una DIRECTIVA DEL PREPROCESADOR. Se ejecuta antes de compilar.
 * El compilador busca el archivo indicado en <...> y copia su contenido
 * en el archivo, justo donde está la directiva.
 * 
 * Incluimos `stdio.h`, que significa "cabecera de entrada/salida estándar" del 
 * inglés "Standard Input / Output Header"
 * Este archivo declara funciones básicas de entrada y salida,
 * incluida la función `printf` que usaremos a continuación.
 * 
 */

#include <stdio.h>

// --- Parte 2: La función principal ---

/*
 * Esta es la FUNCIÓN PRINCIPAL. Todo programa completo en C DEBE tener
 * exactamente una función llamada `main`. La ejecución del programa
 * comienza oficialmente al inicio de la función `main`.
 *
 * Analicemos su firma: `int main(void)`
 *
 * - `int`: Es el TIPO DE RETORNO. Indica que la función `main`
 *   devolverá un valor entero al sistema operativo al finalizar.
 *   Este entero es un "código de salida" que informa si el programa
 *   se ejecutó correctamente.
 *
 * - `main`: Es el NOMBRE obligatorio de la función de inicio. No se puede cambiar.
 *
 * - `(void)`: Define los PARÁMETROS o entradas de la función.
 *   `void` es una palabra clave que significa "nada".
 *   Por tanto, `(void)` indica que esta función no recibe argumentos.
 */

int main(void) 
{ // La llave de apertura `{` marca el inicio del bloque de código de la función.

    // --- Parte 3: Sentencias y funciones ---

    /*
     * `printf()` es una FUNCIÓN que imprime texto formateado en la consola
     * (la ventana de texto donde ejecutarás este programa). Esta función está
     * disponible porque incluimos `<stdio.h>`.
     *
     * El texto entre comillas dobles, `"Hello, World!\n"`, es un LITERAL DE CADENA.
     * Es el dato que pasamos como argumento a la función `printf`.
     *
     * El `\n` al final es una "secuencia de escape" especial que representa un
     * carácter de NUEVA LÍNEA. Indica a la consola que mueva el cursor a la
     * siguiente línea después de imprimir "Hello, World!".
     *
     * Finalmente, el punto y coma `;` al final marca el final de una SENTENCIA en C.
     * Casi todas las líneas ejecutables en C deben terminar con un punto y coma.
     */

    printf("Hello, World!\n");

    /*
     * La sentencia `return` finaliza la ejecución de la función `main`.
     * Envía un valor de retorno al sistema operativo.
     * Por convención, `return 0;` indica que el programa terminó
     * correctamente sin errores.
     */

    return 0;

} // La llave de cierre `}` marca el final del cuerpo de la función.	

/* =============================================================================
 *                                   - FIN LECCIÓN -                           
 * =============================================================================
 *
 * ¡Felicidades por escribir tu primer programa en C!
 *
 * CÓMO COMPILAR Y EJECUTAR ESTE CÓDIGO:
 *
 * 1. Abre una terminal o consola de comandos.
 * 2. Navega hasta el directorio donde guardaste este archivo.
 * 3. Usa el compilador GCC para traducir este código fuente a programa ejecutable.
 *    El siguiente comando realiza lo siguiente:
 *    - `gcc`: Invoca el compilador.
 *    - `-Wall -Wextra`: Activa todas las advertencias para detectar errores.
 *    - `-std=c11`: Indica que usamos el estándar C11 del lenguaje.
 *    - `-o 1_hola_mundo`: Especifica el nombre archivo de salida `1_hello_world`.
 *    - `1_hola_mundo.c`: Es el archivo fuente que se va a compilar.
 *
 *    `gcc -Wall -Wextra -std=c11 -o 01_hola 01_hola_mundo.c`
 *
 * 4. Ejecuta el programa generado:
 *    - En Linux/macOS:   `./1_hello_world`
 *    - En Windows:       `1_hello_world.exe`
 *
 * Deberías ver "Hello, World!" impreso en la consola. 
 *
 */
