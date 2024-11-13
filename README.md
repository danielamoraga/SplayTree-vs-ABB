# Tarea 2: SplayTree vs ABB

## Descripción
Este proyecto busca comparar el tiempo de inserción y búsqueda de elementos en un Splay Tree vs un ABB para 4 escenarios distintos.

## Archivos Principales
- `main.cpp`: Archivo principal que ejecuta los experimentos
- `ABB-structure.hpp`: Define la estructura del ABB con sus métodos de búsqueda e inserción
- `SplayTree-structure.hpp`: Define la estructura del Splay Tree con sus métodos de búsqueda e inserción
- `experiments.hpp`: Contiene las funciones para los 4 escenarios de búsqueda e inserción con los que se experimenta
- `Makefile`: Archivo para automatizar la compilación, ejecución y depuración del programa

# Requisitos
- Compilador de C++ compatible con el estándar C++20
- g++ (GCC) o cualquier otro compilador que soporte C++20
- Sistema operativo Linux o cualquier sistema que soporte GNU Make

# Compilación y Ejecución
El proyecto incluye un `Makefile` para facilitar la compilación y ejecución del programa. A continuación se explican los comandos disponibles:

### Compilar el proyecto

Para compilar el proyecto, usa el siguiente comando:

```bash
make compile
```

### Ejecutar el programa

Este comando compila y ejecuta los experimentos:
```bash
make run
```

## Formato de salida
El programa genera un archivo CSV llamado experiment_data.csv con los resultados de cada experimento. El archivo contiene las siguientes columnas:
- N: Cantidad de elementos a insertar
- M: Cantidad de búsquedas a realizar
- Escenario: Escenario que se está probando
- Tiempo ABB (ns): Tiempo que tarda el ABB en ejecutar el escenario
- Tiempo Splay Tree (ns): Tiempo que tarda el Splay Tree en ejecutar el escenario
