 /*
 * 22_directivas_preprocesador.c - Parte 3, Lección 22: Directivas del
 *                                 Preprocesador
 *
 * Archivo de lección y demostración del preprocesador de C. Explica
 * directivas clave como #include, #define y la compilación condicional,
 * esenciales para gestionar proyectos grandes.
 *
 * Fecha: 15-06-2025
 * Autores:
 *   DunamisMax <github.com/dunamismax>
 *   Andrés Suárez <github.com/asuagar>
 *
 * SPDX-License-Identifier: MIT
 */

#include <stdio.h>

/*
 * ====================================================================
 *                           - INICIO DE LA LECCIÓN -             
 * ====================================================================
 * 
 * Antes de que tu código C llegue al compilador, pasa por el PREPROCESADOR.
 * Su trabajo es simple: es una herramienta de sustitución de texto que busca
 * líneas que empiezan con la almohadilla (`#`) y actúa sobre ellas. Esas
 * líneas son DIRECTIVAS DEL PREPROCESADOR.
 *
 * Las usas desde el primer día, aunque quizá sin conocer los detalles.
 * Veamos las más importantes.
 */

/* --- Parte 1: `#include` revisitado ---
 * Sabes que `#include` "pega" el contenido de otro archivo en este.
 * Hay una diferencia sutil entre las dos formas:
 * 
 * #include `<...>`: para librerías de sistema. El preprocesador  busca en 
 * directorios estándar del sistema. 
 *
 * #include "my_header.h": se usa comillas para tus propios headers. El
 * preprocesador busca primero en el directorio ACTUAL y luego en los
 * directorios estándar. Esto es crucial en proyectos multifichero. */


#include <stdio.h> 

/* --- Parte 2: `#define` para constantes y macros ---
 * `#define` crea MACROS. Una macro es un fragmento de código con nombre.
 * Al usar el nombre, el preprocesador lo sustituye por su contenido.
 * Es sustitución de texto directa.
 *
 * 1) Macros tipo objeto (constantes)
 *    Por convención, las constantes macro van en MAYÚSCULAS.
 *    #define PI 3.14159
 *    #define GREETING "Hello, World!"
 *
 * 2) Macros tipo función
 *    Estas macros aceptan argumentos.
 * 
 *    REGLA DE LOS PARÉNTESIS: rodea cada argumento y TODA la expresión.
 *    Así evitas errores de precedencia tras la sustitución de texto.
 * 
 *    EJEMPLO MALO:
 *    #define BAD_SQUARE(x) x * x
 *    Si llamas `BAD_SQUARE(2 + 3)`, se expande a `2 + 3 * 2 + 3`,
 *    que da `2 + 6 + 3 = 11`. ¡INCORRECTO! 
 * 
 *    EJEMPLO BUENO (regla de los paréntesis): 
 *    Ahora, `SQUARE(2 + 3)` se expande a `((2 + 3) * (2 + 3))`,
 *    que da `5 * 5 = 25`. ¡CORRECTO! 
 */
#define SQUARE(x) ((x) * (x))

/* --- Parte 3: Compilación condicional ---
 * Estas directivas permiten incluir o excluir código según condiciones.
 * Es extremadamente útil, por ejemplo, para mensajes de depuración.
 */

#define DEBUG

int main(void) 
{
    printf("--- Parte 1 y 2: Uso de macros #define ---\n");

    /* Cálculo previo: el preprocesador expandirá PI y SQUARE antes
     * de compilar. */
    double radius = 5.0;
    double area = PI * SQUARE(radius);

    printf("%s\n", GREETING);
    printf("Área de un círculo de radio %.2f: %.2f\n", radius, area);

    int val = 2 + 3;
    printf("El cuadrado de (2 + 3) es %d\n\n", SQUARE(val));

    printf("--- Parte 3: Compilación condicional en acción ---\n");

    /* Este bloque solo se compila si está definido DEBUG. */
#ifdef DEBUG
    printf("DEBUG: Mensaje de depuración.\n");
    printf("DEBUG: El valor de 'area' es %f.\n", area);
#endif

    /* También puedes usar #ifndef (si NO está definido). */
#ifndef RELEASE_MODE
    printf("No es una compilación de release.\n");
#endif

    /* Y comprobaciones con #if. */
#if (10 > 5)
    printf("#if (10 > 5) es verdadero; esta línea se compila.\n");
#endif

    return 0;
}

/*
 * ====================================================================
 *                          - FIN DE LA LECCIÓN -               
 * ====================================================================
 *
 * Ideas clave:
 *
 * 1) El PREPROCESADOR actúa antes del compilador y realiza operaciones de
 *    texto basadas en directivas que comienzan con `#`.
 * 
 * 2) `#include <...>` es para librerías de sistema; `#include "..."` para
 *    tus propios archivos.
 * 
 * 3) `#define` crea macros para constantes o funciones simples. USA
 *    SIEMPRE paréntesis en macros tipo función: `#define N(a) ((a)...)`.
 * 
 * 4) La compilación condicional (`#ifdef`, `#ifndef`, `#if`, `#else`,
 *    `#endif`) permite incluir o excluir código; es ideal para depurar o
 *    para rasgos específicos de plataforma.
 *
 * EL USO MÁS IMPORTANTE DE LA COMPILACIÓN CONDICIONAL: GUARDAS DE HEADER
 *
 * Al crear tus propios `.h`, evita inclusiones dobles con una guarda:
 *
 *   #ifndef MI_HEADER_UNICO_H
 *   #define MI_HEADER_UNICO_H
 *   ... contenido del header ...
 *   #endif 
 *
 * Así, aunque el archivo se `#include` varias veces, el compilador procesa
 * su contenido SOLO UNA VEZ. Para ver la compilación condicional, 
 * comenta `#define DEBUG`, recompila y ejecuta: los mensajes de 
 * depuración desaparecerán.
 *
*/
