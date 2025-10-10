Objetivo:

- Comprender qué son las cadenas (strings) en C y cómo se representan internamente.
- Aprender a usar las funciones más comunes de la biblioteca `<string.h>`.

Concepto clave:

- En C, una cadena es un arreglo (`char[]`) terminado con el carácter nulo `\0`.
- El compilador agrega automáticamente este terminador al declarar cadenas literales.
- Los índices comienzan en 0 y el carácter `\0` marca el final de la cadena.
- La biblioteca `<string.h>` proporciona funciones para medir, copiar, concatenar y comparar cadenas.

Instrucciones:

- Compilar: gcc -Wall -Wextra -std=c11 -o cadenas 09_cadenas.c
- Ejecutar: ./cadenas (Linux/macOS) cadenas.exe (Windows)

Preguntas de reflexión:

- ¿Por qué una cadena en C necesita el carácter `\0`?
- ¿Qué diferencia hay entre `==` y `strcmp()` al comparar cadenas?
- ¿Qué ocurre si el destino en `strcpy()` no tiene espacio suficiente?
- ¿Cómo calcula `strlen()` la longitud de una cadena?
- ¿Qué pasa si olvidas incluir `<string.h>`?

Katas rápidas:

- Kata 1: Crea una cadena `char nombre[] = "Juan";` y muéstrala con `printf("%s")`.
- Kata 2: Copia una cadena en otra con `strcpy()` y cambia una letra.
- Kata 3: Usa `strcat()` para unir dos palabras y mostrar el resultado.
- Kata 4: Compara dos cadenas distintas con `strcmp()` y muestra el valor devuelto.
- Kata 5: Calcula la longitud de una cadena con `strlen()` e imprime el resultado.

Prompt IA:

"Explícame cómo se representan las cadenas en memoria en este código. 
Aclara el papel del carácter nulo `\0` y por qué es necesario. 
Detalla el funcionamiento de las funciones strlen, strcpy, strcat y strcmp con ejemplos. 
Menciona los errores más comunes al manipular cadenas en C sin modificar los nombres del programa."
