/*
 * 07_funciones.c - Parte 1, Lección 7: Funciones
 *
 * Esta lección presenta las funciones, los bloques fundamentales para
 * organizar código en piezas modulares y reutilizables.
 *
 * Fecha: 2025-08-15
 * Autores:
 *   DunamisMax <github.com/dunamismax>
 *   Andrés Suárez <github.com/asuagar>
 *
 * SPDX-License-Identifier: MIT
 */

/*
 * =============================================================================
 *                          - INICIO DE LA LECCIÓN -
 * =============================================================================
 *
 * A medida que los programas crecen, colocar todo el código dentro de `main`
 * se vuelve confuso y difícil de mantener. Si una tarea se repite muchas veces,
 * no es buena idea copiar y pegar el mismo bloque de código.
 *
 * Una FUNCIÓN es un bloque de código con nombre propio que realiza una tarea
 * específica. Piensa en `printf` o `scanf`: son funciones escritas por otros
 * que imprimen o leen datos. Ahora aprenderás a escribir tus propias funciones.
 *
 * Usar funciones permite seguir el principio “DRY”: *Don’t Repeat Yourself*
 * (No te repitas).
 *
 * Hay tres partes esenciales en el uso de funciones:
 * 1. DECLARACIÓN o PROTOTIPO: informa al compilador sobre la existencia de la
 *    función, su nombre, el tipo de valor que devuelve y los parámetros que
 *    acepta.
 * 2. DEFINICIÓN: el código que forma el cuerpo de la función.
 * 3. LLAMADA: la instrucción que ejecuta la función.
 */

#include <stdio.h>

/* --- Parte 1: Declaraciones (Prototipos) --- */

/*
 * Un PROTOTIPO DE FUNCIÓN le indica al compilador cómo es una función antes
 * de definirla. Esto es importante porque el compilador lee el archivo de arriba
 * hacia abajo. Si `main` llama a una función no declarada, se produce un error.
 *
 * Un prototipo se compone de:
 * - El tipo de valor que devuelve la función.
 * - El nombre de la función.
 * - Los tipos de datos de sus parámetros.
 * - Un punto y coma al final.
 */

/* Prototipo de una función sin argumentos ni valor de retorno. */
void print_welcome_message(void);

/* Prototipo de una función que recibe un entero y no devuelve valor. */
void display_character_level(int character_level);

/* Prototipo de una función que recibe dos enteros y devuelve un entero. */
int calculate_damage(int strength, int weapon_power);

/* --- Parte 2: La función `main` (quien llama) --- */

/*
 * La función `main` actúa como un coordinador, llamando a otras funciones
 * para que realicen sus tareas específicas.
 */
int main(void)
{
	/*
	 * LLAMADA DE FUNCIÓN: se ejecuta escribiendo su nombre seguido de
	 * paréntesis. Esta es una llamada a la función `print_welcome_message`.
	 */
	print_welcome_message();

	int player_level = 15;

	/*
	 * Se pasa el valor de `player_level` (15) como ARGUMENTO a la función.
	 */
	display_character_level(player_level);

	/*
	 * Se llama a `calculate_damage` y se guarda su resultado.
	 * Los valores 20 y 8 son los ARGUMENTOS introducidos.
	 */
	int total_damage = calculate_damage(20, 8);

	printf("Con fuerza 20 y arma de poder 8...\n");
	printf("El daño total calculado es: %d\n", total_damage);

	return 0;	/* Fin del programa principal. */
}

/* --- Parte 3: Definiciones de funciones (implementaciones) --- */

/*
 * Debajo de `main` se definen las funciones.
 * La definición incluye la cabecera (similar al prototipo, sin punto y coma)
 * y el cuerpo entre llaves `{}`.
 */

/*
 * Imprime un mensaje de bienvenida en la consola.
 *
 * Ejemplo de función sin argumentos ni valor de retorno.
 * `void` como tipo de valor de retorno indica que no devuelve nada.
 * `(void)` como parámetro indica que no acepta argumentos.
 */
void print_welcome_message(void)
{
	printf("--- ¡Bienvenido a la demostración de funciones! ---\n\n");
}

/*
 * Muestra el nivel del personaje.
 * @param character_level Nivel que se mostrará.
 *
 * Esta función recibe un entero. Dentro, el valor se representa mediante
 * el PARÁMETRO `character_level`. Un PARÁMETRO es una variable local
 * que almacena el valor del argumento pasado en la llamada.
 */
void display_character_level(int character_level)
{
	printf("Tu personaje es de nivel %d.\n\n", character_level);
}

/*
 * Calcula el daño total combinando fuerza y poder del arma.
 * @param strength Valor de fuerza del personaje.
 * @param weapon_power Poder del arma equipada.
 * @return Daño total calculado.
 *
 * Esta función recibe dos enteros y devuelve un entero.
 * La palabra clave `return`:
 * 1. Finaliza la ejecución de la función.
 * 2. Devuelve el valor al lugar donde fue llamada.
 */
int calculate_damage(int strength, int weapon_power)
{
	int calculated_value = strength + (weapon_power * 2);
	return calculated_value;	/* Devuelve el valor al llamador (main). */
}

/*
 * =============================================================================
 *                           - FIN DE LA LECCIÓN -
 * =============================================================================
 *
 * En esta lección aprendiste a crear y usar funciones:
 *
 * Puntos clave:
 * - Las funciones dividen un problema en partes pequeñas y reutilizables.
 * - El PROTOTIPO declara la función antes de su uso.
 * - La DEFINICIÓN contiene el código que ejecuta la tarea.
 * - La LLAMADA ejecuta la función.
 * - Los PARÁMETROS son variables que reciben los valores de entrada.
 * - Los ARGUMENTOS son los valores reales pasados al llamar.
 * - `return` envía un valor de salida al llamador.
 * - `void` indica que no hay valor de retorno.
 */
