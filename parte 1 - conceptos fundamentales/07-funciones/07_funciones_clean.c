/* SPDX-License-Identifier: MIT */
/*
 * Filename: 07_funciones_clean.c
 *
 * Purpose:
 *   Presenta las funciones como bloques fundamentales para organizar
 *   el código en piezas modulares y reutilizables.
 *
 * Design Notes:
 *   Este archivo forma parte de la serie educativa de ejemplos en C.
 *   El objetivo es enseñar estructura, claridad y documentación.
 *
 * References:
 *   NASA/JPL Institutional Coding Standard for the C Programming Language.
 *
 * Author(s):
 *   DunamisMax   <github.com/dunamismax>
 *   Andrés Suárez <github.com/asuagar>
 *
 * Creation Date: 2025-10-08
 * Coding Standard: NASA/JPL C (4 espacios, llaves en nueva línea)
 */

#include <stdio.h>   /* Para printf() */

/* Declaraciones de funciones */
void print_welcome_message(void);
void display_character_level(int character_level);
int calculate_damage(int strength, int weapon_power);

/*
 * Función: main
 * -------------------------------------
 *  Punto de entrada del programa.
 *
 *  Llama a las funciones de demostración: muestra un mensaje de bienvenida,
 *  imprime el nivel del personaje y calcula el daño total de un ataque.
 *
 *  Retorna:
 *    0  - Finalización correcta del programa.
 */
int main(void)
{
    int player_level = 15;
    int total_damage = 0;

    print_welcome_message();

    display_character_level(player_level);

    total_damage = calculate_damage(20, 8);
    printf("Con fuerza 20 y arma 8, daño total: %d\n", total_damage);

    /* Retornar código de éxito explícito */
    return 0;
}

/*
 * Función: print_welcome_message
 * -------------------------------------
 *  Muestra un mensaje de bienvenida al usuario.
 *
 *  Parámetros:
 *    Ninguno.
 *
 *  Retorna:
 *    Nada (void).
 */
void print_welcome_message(void)
{
    printf("--- Demostración de funciones ---\n\n");
}

/*
 * Función: display_character_level
 * -------------------------------------
 *  Muestra el nivel actual del personaje.
 *
 *  Parámetros:
 *    character_level  - Nivel actual del personaje.
 *
 *  Retorna:
 *    Nada (void).
 */
void display_character_level(int character_level)
{
    printf("Nivel del personaje: %d\n\n", character_level);
}

/*
 * Función: calculate_damage
 * -------------------------------------
 *  Calcula el daño total de un ataque.
 *
 *  Parámetros:
 *    strength      - Nivel de fuerza del personaje.
 *    weapon_power  - Poder del arma equipada.
 *
 *  Retorna:
 *    Daño total calculado (entero).
 */
int calculate_damage(int strength, int weapon_power)
{
    int total_damage = 0;

    total_damage = strength + (weapon_power * 2);

    return total_damage;
}

