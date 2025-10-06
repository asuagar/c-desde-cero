Objetivo:

Aprender a leer datos del teclado en C con scanf().

Concepto clave:

scanf() necesita la dirección de memoria (&variable) para guardar el dato.
Los especificadores de formato indican el tipo de dato esperado.

Instrucciones:

- Compila: gcc -Wall -Wextra -std=c11 -o 3_entrada 3_input_usuario.c
- Ejecuta: ./entrada (Linux/macOS) o entrada.exe (Windows)

Preguntas de reflexión:

- ¿Por qué scanf necesita & antes del nombre de la variable?
- ¿Qué diferencia hay entre %f y %lf?
- ¿Qué problema causa el carácter '\n' en el búfer?
- ¿Por qué " %c" evita ese error?
- ¿Qué pasaría si introduces un valor no numérico?

Katas rápidas:

- Lee un número entero y calcula su cuadrado.
- Pide un decimal y muestra su valor con dos decimales.
- Lee dos enteros separados por un espacio y muestra su suma.

