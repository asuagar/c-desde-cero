Objetivo:

- Mostrar la estructura mínima de un programa en C.
- Imprimir un mensaje por consola.

Concepto clave:

- main como punto de entrada.
- printf para salida estándar.
- Compilación C11 con GCC.

Instrucciones:

- Compila: gcc -Wall -Wextra -std=c11 -o hola 01_hola_mundo.c
- Ejecuta: ./hola (Linux/macOS) hola.exe (Windows)

El compilador GCC (GNU Compiler collection) traduce este código fuente a 
un programa ejecutable. El comando realiza lo siguiente:
    - `gcc`: Invoca el compilador.
    - `-Wall -Wextra`: Activa todas las advertencias para detectar posibles errores.
    - `-std=c11`: Indica que usamos el estándar C11 del lenguaje.
    - `-o 1_hola`: Especifica que el archivo de salida se llamará `1_hola`.
    - `1_hello_world.c`: Indica el archivo fuente que se va a compilar.

Preguntas de reflexión:

- ¿Qué significa int en int main(void)?
- ¿Por qué usamos \n en la cadena?
- ¿Qué informa return 0 al sistema?
- ¿Qué aportan -Wall y -Wextra?
- ¿Qué hace stdio.h por nosotros?

Katas rápidas:

- Kata 1: Cambia el mensaje a "Hello, Control Systems!".
- Kata 2: Imprime dos líneas usando dos llamadas a printf.
- Kata 3: Devuelve 1 en lugar de 0. Observa el código de salida del proceso.

Prompt IA:

"Explícame este programa C línea a línea. Señala riesgos comunes (includes, retorno de main, formato). Explica como compilarlo y los parámetros aconsejables. "
