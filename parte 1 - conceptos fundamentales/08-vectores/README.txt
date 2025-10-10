Objetivo:

- Comprender qué es un vector (array) y para qué se utiliza.
- Aprender a declarar, inicializar y recorrer arreglos con bucles.

Concepto clave:

- Un vector almacena varios elementos del mismo tipo en posiciones contiguas de memoria.
- C usa índices que comienzan en 0 (zero-based indexing).
- Acceder a un índice fuera del rango válido produce comportamiento indefinido.
- Los vectores se combinan con bucles para procesar conjuntos de datos de forma eficiente.

Instrucciones:

- Compilar: gcc -Wall -Wextra -std=c11 -o vector 08_vectores.c
- Ejecutar: ./vectores (Linux/macOS) vectores.exe (Windows)

Preguntas de reflexión:

- ¿Por qué los índices comienzan en 0?
- ¿Qué ocurre si intentas acceder a high_scores[5]?
- ¿Qué ventajas aporta usar bucles para procesar arreglos?
- ¿Por qué el tamaño de un arreglo debe ser fijo en tiempo de compilación?

Katas rápidas:

- Kata 1: Cambia los valores de `high_scores` e imprime el nuevo máximo.
- Kata 2: Usa un bucle `for` para mostrar los índices junto con los valores.
- Kata 3: Crea un arreglo `int edades[5]` e inicialízalo con tus valores preferidos.
- Kata 4: Añade un cálculo de promedio de las temperaturas.
- Kata 5: Declara un arreglo `char nombre[]` con tu nombre y muestra cada carácter en una línea distinta.

Prompt IA:

"Explícame cómo se declaran, inicializan y recorren los arreglos en este código. 
Aclara por qué los índices comienzan en 0 y qué errores comunes pueden surgir al acceder a posiciones inválidas. 
Sugiere ejemplos adicionales de uso de arreglos con bucles for, sin cambiar los nombres ni la estructura del programa."
