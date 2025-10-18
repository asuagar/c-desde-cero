/*
 * 21_manipulacion_bit.c - Parte 3, Manipulación de Bits
 *
 * Este archivo sirve como lección y demostración para la manipulación de bits.
 * Introduce los operadores bitwise y muestra cómo manipular directamente los
 * bits individuales de los datos, una técnica poderosa para optimización 
 * y control.
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
 *                             - INICIO DE LECCION -                            
 * =============================================================================
 *
 * C es un lenguaje que opera muy cerca del hardware. Todos los datos en su
 * computadora—enteros, caracteres, etc.—son finalmente almacenados como una 
 * secuencia de BITS (dígitos binarios), que son 0 o 1.
 *
 * C proporciona un conjunto especial de OPERADORES BITWISE que le permiten 
 * manipular estos bits individuales directamente. Esta es una característica 
 * de bajo nivel que es increíblemente poderosa para tareas como:
 * - Controlar dispositivos de hardware donde cada bit en un registro 
 *   tiene un significado.
 * - Escribir código altamente eficiente para algoritmos específicos.
 * - Almacenar múltiples flags booleanos (verdadero/falso) en un solo byte.
 *
 * --- Los Operadores Bitwise ---
 *
 * &  (AND Bitwise):     Establece un bit a 1 si AMBOS bits son 1.
 * |  (OR Bitwise):      Establece un bit a 1 si CUALQUIERA de los bits es 1.
 * ^  (XOR Bitwise):     Establece un bit a 1 si los bits son DIFERENTES.
 * ~  (NOT Bitwise):     Invierte todos los bits.  
 * << (Desplazamiento Izquierda): Desplaza todos los bits a la izquierda 
 *                                un número específico de lugares.
 * >> (Desplazamiento Derecha):   Desplaza todos los bits a la derecha 
 *                                un número específico de lugares.
 */

#include <stdio.h>
#include <stdint.h> /* Para uint8_t, un tipo de entero sin signo de 8 bits. */

/* --- Función auxiliar para visualizar bits  ---
 * Para comprender la manipulación de bits, se necesitan ver los bits.
 * Esta función imprime la representación binaria de un byte.
 * Un byte es un número de 8 bits. Usaremos `uint8_t` para la representación
 * del byte u 8-bits sin signo.
*/
void print_binary(uint8_t byte) 
{
    /* prefijo "0b" indica número binario */
    printf("0b"); 
    /* loop desde el bit más significativo (7) hasta el menor (0)*/
    for (int i = 7; i >= 0; i--) {
        /* `(byte >> i)` mueve el bit de interés a la posición 0 y le aplica
         * `& 1`. Esto compara el bit movido con el bit 1. Si el bit es 1, 
	 * el resultado es 1; en caso contrario será 0.
	*/
        printf("%d", (byte >> i) & 1);
    }
}

int main() 
{

    /* Usemos dos números pequeños para nuestra demostración. */
    a = 5; /* Binario: 00000101 */
    b = 9; /* Binario: 00001001 */

    printf("--- Parte 1: Operaciones Bitwise Basicas ---\n");
    printf("a = %2d = ", a);
    print_binary(a);
    printf("\n");
    printf("b = %2d = ", b);
    print_binary(b);
    printf("\n\n");

    /* Bitwise AND */
    result_and = a & b; /* 00000101 & 00001001 = 00000001 (1) */
    printf("a & b = %2d = ", result_and);
    print_binary(result_and);
    printf("\n");

    /* Bitwise OR */
    result_or = a | b; /* 00000101 | 00001001 = 00001101 (13) */
    printf("a | b = %2d = ", result_or);
    print_binary(result_or);
    printf("\n");

    /* Bitwise XOR */
    result_xor = a ^ b; /* 00000101 ^ 00001001 = 00001100 (12) */
    printf("a ^ b = %2d = ", result_xor);
    print_binary(result_xor);
    printf("\n");

    /* Bitwise NOT */
    result_not_a = ~a; /* ~00000101 = 11111010 (250) */
    printf("  ~a  = %3d = ", result_not_a);
    print_binary(result_not_a);
    printf("\n\n");

    /* --- Parte 2: Operaciones de Desplazamiento (Shift) --- */
    printf("--- Parte 2: Operaciones de Desplazamiento ---\n");
    c = 12; /* Binario: 00001100 */

    printf("c = %2d = ", c);
    print_binary(c);
    printf("\n");

    /* Desplazamiento a la Izquierda (equivalente a multiplicar por 2^n) */
    left_shifted = c << 2; /* 12 * 2^2 = 12 * 4 = 48 (00110000) */
    printf("c << 2 = %2d = ", left_shifted);
    print_binary(left_shifted);
    printf("\n");

    /* Desplazamiento a la Derecha (equivalente a división entera por 2^n) */
    right_shifted = c >> 1; /* 12 / 2^1 = 12 / 2 = 6 (00000110) */
    printf("c >> 1 = %2d = ", right_shifted);
    print_binary(right_shifted);
    printf("\n\n");

    /* --- Parte 3: Uso Práctico - BITMASKS para Flags --- 
     * Una máscara de bits (bitmask) se utiliza para comprobar
     * un bit específico dentro de un byte u otro valor. 
     * Se puede interpretar como múltiples estados on/off almacenados. 
     * Cada posición de bit representa un flag diferente. 
     */

    printf("--- Parte 3: Bitmasking Practico ---\n");
    const uint8_t FLAG_READ_ACCESS = 1 << 0;    // 00000001 (1)
    const uint8_t FLAG_WRITE_ACCESS = 1 << 1;   // 00000010 (2)
    const uint8_t FLAG_EXECUTE_ACCESS = 1 << 2; // 00000100 (4)
    const uint8_t FLAG_IS_ADMIN = 1 << 7;       // 10000000 (128)

    uint8_t user_permissions = 0; /* Empezar sin permisos. */
    printf("Permisos iniciales: ");
    print_binary(user_permissions);
    printf("\n");

    /* 1. ESTABLECER un bit (dar permiso) usando OR */
    user_permissions = user_permissions | FLAG_READ_ACCESS;
    user_permissions = user_permissions | FLAG_WRITE_ACCESS;
    printf("Luego de dar R/W:    ");
    print_binary(user_permissions);
    printf("\n");

    /* 2. COMPROBAR un bit (¿tienen permiso?) usando AND */
    if (user_permissions & FLAG_WRITE_ACCESS)
        printf("Usuario tiene acceso de ESCRITURA.\n");
    
    if (!(user_permissions & FLAG_EXECUTE_ACCESS)) 
        printf("Usuario NO tiene acceso de EJECUCION.\n");

    /* 3. LIMPIAR un bit (revocar permiso) usando AND con NOT */
    user_permissions = user_permissions & ~FLAG_WRITE_ACCESS;
    printf("Luego de revocar W:  ");
    print_binary(user_permissions);
    printf("\n");

    /* 4. ALTERNAR un bit (cambiar su estado) usando XOR */
    user_permissions = user_permissions ^ FLAG_READ_ACCESS; /* Apagarlo */
    user_permissions = user_permissions ^ FLAG_READ_ACCESS; /* Encenderlo de nuevo */
    printf("Luego de alternar R 2x:");
    print_binary(user_permissions);
    printf("\n");

    return 0;
} /* Fin de main */

/*
 * =============================================================================
 *                              - FIN DE LECCION -                              
 * =============================================================================
 *
 * Puntos Clave:
 *
 * 1.  Los operadores bitwise (`&`, `|`, `^`, `~`, `<<`, `>>`) le permiten manipular
 * directamente los 0s y 1s que componen los tipos de datos numéricos.
 * 2.  Una BITMASK es un valor (a menudo una constante) utilizado para apuntar a bits
 * específicos en otra variable para establecerlos, limpiarlos o comprobarlos.
 * 3.  Los patrones comunes para el bitmasking son:
 * - Establecer bit:      `flags = flags | MASK;`
 * - Limpiar bit:         `flags = flags & ~MASK;`
 * - Comprobar bit:       `if (flags & MASK) { ... }`
 * - Alternar bit:        `flags = flags ^ MASK;`
 * 4.  Los operadores de desplazamiento proporcionan una forma muy rápida de realizar
 * multiplicaciones y divisiones por potencias de dos.
 *
 * Esta es una habilidad de bajo nivel pero esencial para cualquier programador C serio.
 *

 */
