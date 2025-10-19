
<p align="center">
  <a href="https://en.wikipedia.org/wiki/C11_(C_standard_revision)"><img src="https://img.shields.io/badge/C11-Estándar-00599C.svg" alt="Estándar C11"></a>
  <a href="https://www.gnu.org/software/make/"><img src="https://img.shields.io/badge/Make-Sistema_de_Construcción-3071A4.svg" alt="Make Build System"></a>
  <a href="https://en.wikipedia.org/wiki/Ncurses"><img src="https://img.shields.io/badge/UI-ncurses-9cf" alt="ncurses"></a>
  <a href="https://clang.llvm.org/"><img src="https://img.shields.io/badge/Clang-17+-3071A4.svg?logo=llvm" alt="Versión Clang"></a>
  <a href="https://opensource.org/licenses/MIT"><img src="https://img.shields.io/badge/Licencia-MIT-green.svg" alt="Licencia MIT"></a>
</p>


# C Desde Cero

Este curso usa un método único y práctico: **la lección está en el código**.
Cada concepto se aprende leyendo los comentarios dentro de un único archivo C ejecutable por tema.

## Características Principales

- **Aprende directamente en el código**: Cada lección se enseña dentro de los comentarios de un solo archivo C ejecutable  
- **Sin requisitos previos**: Diseñado para principiantes absolutos sin experiencia en programación  
- **Aprendizaje basado en proyectos**: Construye herramientas, juegos y aplicaciones reales de consola  
- **Enfoque en seguridad de memoria**: Aprende buenas prácticas de programación segura desde el inicio  

<p align="center">
  <img src="https://github.com/dunamismax/images/blob/main/c/C-Logo.png" alt="Logo del Lenguaje C" width="150" />
</p>

## Flujo de Trabajo

```bash
# Ve a cualquier lección
cd Parte1_Conceptos_Básicos/01_HelloWorld

# Lee la lección (comentarios en el archivo .c)
cat 1_hello_world.c

# Compila con las banderas recomendadas
gcc -Wall -Wextra -std=c11 -o programa archivo.c

# Ejecuta el programa
./programa

# En lecciones con Makefile
make
./programa
```

## Compatibilidad

Funciona en todas las plataformas principales que admiten compiladores C.

- **macOS**: desarrollo nativo con las herramientas de línea de comandos de Xcode.  
- **Linux**: uso de GCC o Clang con los paquetes estándar de desarrollo.  
- **Windows**: compatible con MinGW-w64, Clang o el Subsistema de Windows para Linux (WSL).

## Estructura del Curso

```sh
├── Parte1_Conceptos_Básicos/        # Fundamentos iniciales
│   ├── 01_HelloWorld/               # Primer programa y compilación
│   ├── 02_Variables/                # Tipos de datos y memoria
│   ├── 03_EntradaUsuario/           # Programas interactivos
│   ├── 04_Operadores/               # Cálculos y lógica
│   ├── 05_Condicionales/            # Toma de decisiones
│   ├── 06_Bucles/                   # Repetición e iteración
│   ├── 07_Funciones/                # Programación modular
│   ├── 08_Vectores/                 # Colecciones de datos
│   └── 09_Cadenas/                  # Manipulación de texto
|
├── Parte2_Profundizando_en_C/       # Conceptos intermedios
│   ├── 10_Punteros/                 # Direcciones de memoria
│   ├── 11_PunterosVectores/         # Aritmética de punteros
│   ├── 12_Estructuras/              # Tipos de datos personalizados
│   ├── 13_MemoriaDinámica/          # malloc y gestión de memoria
│   ├── 14_EntradaSalidaFicheros/    # Almacenamiento persistente
│   └── 15_LineaComandos/            # argc y argv
|
├── Parte3_Camino_Avanzado/          # Programación avanzada
│   ├── 16_Calculadora/              # Primer proyecto completo
│   ├── 17_RegistrosEstudiantes/     # Aplicación tipo base de datos
│   ├── 18_PunterosFuncion/          # Callbacks y despacho
│   ├── 19_Recursión/                # Algoritmos recursivos
│   ├── 20_ListasEnlazadas/          # Estructuras dinámicas
│   ├── 21_ManipulaciónBits/         # Programación de bajo nivel
│   ├── 22_Preprocesador/            # Proyectos multifichero
│   ├── 23_UnionesEnums/             # Tipos especializados
│   ├── 24_StaticExtern/             # Alcance y enlace de variables
│   └── 25_EditorTexto/              # Proyecto final de editor
|
├── Parte4_Programación_Sistemas/    # Interacción con el sistema operativo
│   ├── 26_ServidorSocket/           # Programación de redes
│   ├── 27_BuildGrep/                # Herramientas de consola
│   ├── 28_TablaHash/                # Implementación de estructuras
│   ├── 29_TinyShell/                # Gestión de procesos
│   └── 30_AnalizadorMultihilo/      # Programación concurrente
|
└── Parte5_Aplicaciones_Expertas/    # Desarrollo a gran escala
    ├── 31_Makefiles/                # Automatización de compilación
    ├── 32_BibliotecasExternas/      # Enlace de librerías
    ├── 33_InterfazTerminal/         # Interfaces con ncurses
    ├── 34_AnalisisDatos/            # Archivos de configuración
    └── 35_AventuraTexto/            # RPG final tipo aventura
```

### Créditos y Licencia

Este proyecto se basa en el curso original [**C From the Ground Up**](https://github.com/dunamismax/c-from-the-ground-up), desarrollado también por **DunamisMax** y distribuido bajo licencia **MIT**.    

Todos los archivos y modificaciones adicionales de este repositorio se publican bajo la misma licencia **MIT**.

