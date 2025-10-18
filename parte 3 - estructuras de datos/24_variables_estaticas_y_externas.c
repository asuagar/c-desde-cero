 /*
 * 24_variables_estaticas_y_externas.c - Parte 3, Variables static y extern
 *
 * Este archivo sirve como lección y demostración sobre las clases de
 * almacenamiento, concretamente las palabras clave `static` y `extern`.
 * Explica cómo controlan la vida útil, el ámbito y el enlace de las
 * variables a través de distintos archivos.
 *
 * Fecha: 15-06-2025
 * Autores:
 *   DunamisMax <github.com/dunamismax>
 *   Andrés Suárez <github.com/asuagar>
 *
 * SPDX-License-Identifier: MIT
 */

/*
 * ====================================================================
 *                           - INICIO DE LA LECCIÓN -             
 * ====================================================================
 *
 * A medida que los programas crecen, necesitamos mayor control sobre las
 * variables y funciones. Debemos responder dos preguntas clave:
 *
 * 1) VIDA ÚTIL: ¿Cuánto tiempo existe una variable en memoria?
 * 2) ENLACE (VISIBILIDAD): ¿Qué partes del código pueden verla?
 *
 * Las palabras clave `static` y `extern` son nuestras herramientas para
 * gestionarlo.
 *
 * `static` – La palabra clave "privada"
 * Tiene dos significados distintos según dónde se use, pero ambos
 * relacionados con hacer las cosas más "persistentes" o "privadas".
 *
 * `extern` – La palabra clave de "declaración pública"
 * Se usa para DECLARAR una variable global definida en otro archivo.
 * Indica al compilador: “No te preocupes, esta variable existe en otro
 * sitio; el enlazador la encontrará y la conectará”.
 */

#include <stdio.h>

/* --- Parte 1: `static` dentro de una función (control de VIDA ÚTIL) ---
 *
 * Dentro de una función, `static` cambia la duración de almacenamiento.
 * 
 * - Una variable local normal (auto) se crea en la pila al llamar
 *   a la función y se destruye al salir de ella.
 * 
 * - Una variable local `static` se crea solo una vez y existe durante
 *   toda la ejecución del programa. Conserva su valor entre llamadas. 
 */
void regular_counter()
{
    int count = 0; /* Se reinicia cada vez que se llama. */
    count++;
    printf("Contador normal: %d\n", count);
}

void static_counter()
{
    /* Se incializa a 0 solo la PRIMERA vez. En las sucesivas llamadas,
     * conserva su valor. 
     */
    static int count = 0;
    count++;
    printf("Contador estático: %d\n", count);
}

/* --- Parte 2: `static` a nivel de archivo (control de ENLACE) --- 
 *
 * Cuando se usa en variables o funciones globales, `static` cambia el
 * enlace de "externo" a "interno".
 * 
 * - Una variable con ENLACE EXTERNO (por defecto) puede verse desde
 *   otros archivos .c.
 * 
 * - Una variable con ENLACE INTERNO es privada a este archivo.
 *   Es una herramienta clave para la ENCAPSULACIÓN. 
 */
int g_public_variable = 100; /* Enlace EXTERNO. Visible globalmente. */

static int g_private_variable = 42; /* Enlace INTERNO. Privado aquí. */

/* También aplica a funciones. */
static void private_helper_function()
{
    printf("Esta es una función privada. No puede llamarse desde otros archivos.\n");
}

/* --- Parte 3: `extern` para compartir variables globales --- */
/* Imagina que una variable definido en otro fichero llmado `globals.c``:
 *
 *   int g_shared_counter = 500;
 *
 * Para usar `g_shared_counter` aquí dentro, debemos DECLARARLA con `extern`.
 * Esto le dice al compilador que tenemos intención de usarla, 
 * pero está definida en otro lugar. En este tutorial de un solo archivo, 
 * la definiremos al final del archivo. 
 */
extern int g_late_defined_variable; /* Declaración, no definición. */

int main(void)
{
    printf("--- Parte 1: `static` y vida útil ---\n");
    printf("Llamando a los contadores tres veces:\n");
    regular_counter();
    static_counter();
    printf("---\n");
    regular_counter();
    static_counter();
    printf("---\n");
    regular_counter();
    static_counter();
    printf("\n");

    printf("--- Parte 2: `static` y enlace interno ---\n");
    printf("Variable global pública: %d\n", g_public_variable);
    printf("Variable estática privada: %d\n", g_private_variable);
    private_helper_function();
    printf("\n");

    printf("--- Parte 3: Uso de `extern` ---\n");
    printf("Variable tardíamente definida (extern): %d\n",
           g_late_defined_variable);

    return 0;
}

/* DEFINICIÓN de la variable declarada como `extern` arriba.
 * Debido a que la función `main` estaba advertida gracias 
 * a la declaración `extern`, el programa se compiló correctamente.
 * En un proyecto real estaría en otro archivo .c. */

int g_late_defined_variable = 999;

/*
 * ====================================================================
 *                          - FIN DE LA LECCIÓN -               
 * ====================================================================
 * 
 * Ideas clave:
 *
 * 1) `static` tiene dos significados según el contexto:
 *    - DENTRO de una función: crea una variable que persiste toda la
 *      ejecución del programa.
 *    - FUERA de una función: crea una variable o función global privada
 *      al archivo actual (enlace interno).
 *
 * 2) Por defecto, las variables y funciones globales tienen ENLACE
 *    EXTERNO, es decir, pueden compartirse entre archivos .c.
 *
 * 3) `extern` se usa para DECLARAR variables globales definidas en otros
 *    archivos, permitiendo compartirlas entre módulos.
 *
 * Estos conceptos son fundamentales para estructurar proyectos C
 * multifichero. Usa `static` para ocultar detalles y `extern`
 * (normalmente a través de un header) para exponer las partes públicas.
 *
 */