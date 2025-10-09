Objetivo:

- Aprender a crear y usar funciones en C.
- Comprender la diferencia entre declaración, definición y llamada.

Concepto clave:

- Una función es un bloque de código con nombre que realiza una tarea específica.
- El prototipo informa al compilador de su existencia antes de usarla.
- Los parámetros reciben valores de entrada y `return` devuelve un resultado.
- `void` indica que la función no devuelve nada.

Instrucciones:

- Compilar: gcc -Wall -Wextra -std=c11 -o funciones 07_funciones.c
- Ejecutar: ./functiones (Linux/macOS) functions.exe (Windows)

Preguntas de reflexión:

- ¿Por qué no se pueden definir todas las funciones dentro de `main`?
- ¿Qué diferencia hay entre parámetro y argumento?
- ¿Qué sucede si olvidas declarar un prototipo antes de `main`?
- ¿Qué significa `void` en la declaración de una función?
- ¿Por qué es útil devolver un valor con `return`?

Katas rápidas:

- Kata 1: Crea una nueva función que calcule el doble de un número.
- Kata 2: Modifica `calculate_damage` para incluir un multiplicador adicional.
- Kata 3: Añade una función sin parámetros que imprima tu nombre.

Prompt IA:

"Explícame cómo se definen, declaran y llaman las funciones en este código. 
Diferencia entre parámetros y argumentos con ejemplos. 
Señala errores típicos como olvidar el prototipo o usar mal el tipo de retorno. 
Propón una función adicional coherente con el estilo del programa."
