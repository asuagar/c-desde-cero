Objetivo:

- Aprender a repetir instrucciones mediante bucles.
- Diferenciar `for`, `while` y `do-while`.

Concepto clave:

- Un bucle repite código mientras se cumpla una condición.
- `for` se usa cuando se conoce el número de repeticiones.
- `while` se usa cuando no se conoce.
- `do-while` se ejecuta al menos una vez.

Instrucciones:

- Compilar: gcc -Wall -Wextra -std=c11 -o bucles 06_bucles.c
- Ejecutar: ./bucles  (Linux/macOS) bucles (Windows)
- Prueba cada bloque por separado.

Preguntas de reflexión:

- ¿Qué diferencia hay entre `while` y `do-while`?
- ¿Qué ocurre si olvidas actualizar la condición dentro del bucle?
- ¿Cuándo usarías un `for` en lugar de un `while`?
- ¿Qué significa “bucle infinito”?
- ¿Por qué se usa `i++` y qué hace realmente?

Katas rápidas:

- Kata 1: Crea un `for` que cuente de 1 a 10.
- Kata 2: Usa `while` para pedir una contraseña hasta que sea correcta.
- Kata 3: Crea un bucle que sume los números del 1 al 5 y muestre el total.

Prompt IA:

"Explícame el funcionamiento de los bucles for, while y do-while en este código. 
Comenta la diferencia entre evaluar la condición al inicio o al final. 
Señala errores comunes como bucles infinitos o variables no inicializadas. 
Sugiere un ejemplo adicional con un contador decreciente, sin cambiar los nombres existentes."
