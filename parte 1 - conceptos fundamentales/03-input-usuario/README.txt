Objetivo:

Aprender a leer datos del teclado en C con scanf().

Concepto clave:

scanf() necesita la dirección de memoria (&variable) para guardar el dato.
Los especificadores de formato indican el tipo de dato esperado.

Instrucciones:

- Compila: gcc -Wall -Wextra -std=c11 -o entrada 03_input_usuario.c
- Ejecuta: entrada (Linux/macOS) entrada.exe (Windows)

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

Prompt IA:

"Explícame cómo funcionan las operaciones de entrada y salida en este programa C. 
Detalla el uso de printf y scanf, incluyendo el manejo de espacios en blanco y formatos de lectura. 
Señala errores comunes de principiantes con scanf (como olvidarse del &). 
Propón ejemplos alternativos que muestren cómo capturar distintos tipos de datos sin modificar los nombres del código original."

