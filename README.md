# Algoco-t2: Tarea 2 de Algoritmos y Complejidad

## Descripción del Proyecto
Este proyecto consiste en la implementación de algoritmos para calcular la distancia de edición entre dos cadenas de texto utilizando enfoques de fuerza bruta y programación dinámica. Además, se han implementado funciones de costo para las operaciones de inserción, eliminación, sustitución y transposición, con valores configurables a través de archivos de texto.

Los resultados experimentales se generaron inicialmente en formato `.txt` desde el código principal (`main.cpp`) utilizando la librería `chronos` para medir los tiempos. Posteriormente, estos resultados se organizaron manualmente en archivos CSV para facilitar su análisis.

## Requisitos Previos
- **Compilador de C++** (por ejemplo, `g++`)
- **Make** (para compilar el código con el Makefile)
- **Python 3**, **pandas** y **matplotlib** (para ejecutar el script de análisis)

Instala las herramientas necesarias con:
```bash
sudo apt-get install g++ make python3 python3-pip
pip3 install pandas
pip install matplotlib
```

## Estructura del Proyecto
```
Algoco-t2-main/
├── data/
│   ├── cost_insert.txt
│   ├── cost_delete.txt
│   ├── cost_replace.txt
│   ├── cost_transpose.txt
│   ├── resultados.txt
│   ├── resultados-T.txt
│   ├── resultados.csv
│   ├── resultados-T.csv
│   └── analisis.py
|
├── costos.h
├── costos.cpp
├── main.cpp
├── Makefile
├── README.md

```

## Configuración Inicial
1. **Asegúrate de tener los archivos de costos** en la carpeta `data/`. Estos archivos deben contener los valores de los costos de las operaciones de edición.

2. **Compila el proyecto** utilizando el `Makefile`. Desde la terminal, navega al directorio del proyecto y ejecuta:
```bash
make
```

Este comando compilará los archivos `main.cpp` y `costos.cpp`, generando un ejecutable llamado `programa`.

## Ejecución del Proyecto
Para ejecutar el programa, usa el siguiente comando en la terminal:
```bash
./programa
```
El programa cargará los archivos de costos desde la carpeta `data/` y realizará las operaciones de edición según las entradas definidas en el código.

## Limpieza del Proyecto
Para eliminar el ejecutable y los archivos objeto (“.o”), ejecuta:
```bash
make clean
```
## Explicación de los Algoritmos Implementados
### Algoritmo de Backtracking
El algoritmo de backtracking explora todas las posibles soluciones para encontrar la distancia de edición mínima entre dos cadenas. Utiliza una estrategia recursiva que incluye las operaciones de inserción, eliminación, sustitución y transposición.

### Algoritmo de Programación Dinámica
El algoritmo de programación dinámica utiliza una matriz para almacenar los costos mínimos parciales de transformación entre subcadenas, evitando el cálculo repetido de subproblemas. Esto permite resolver el problema de manera más eficiente que el backtracking.

## Archivos de Costos
Los archivos de costos deben estar en la carpeta `data/` y seguir los formatos descritos:
- **cost_insert.txt** y **cost_delete.txt**: Contienen 26 valores en una sola línea, uno por cada letra del alfabeto.
- **cost_replace.txt** y **cost_transpose.txt**: Contienen una matriz de 26x26, donde cada fila y columna representa un par de letras del alfabeto.

## Notas Adicionales
- **Modificación de los costos**: Si deseas cambiar los valores de los costos, edita los archivos `cost_insert.txt`, `cost_delete.txt`, `cost_replace.txt` y `cost_transpose.txt` en la carpeta `data/`.
- **Verifica que las rutas de los archivos** estén correctas en el código si decides mover los archivos de costos a otra ubicación.

---
© 2024 Algoco-t2 Project
