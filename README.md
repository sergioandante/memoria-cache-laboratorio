# Proyecto: Análisis y Optimización de Multiplicación de Matrices

## Descripción

Este proyecto contiene la implementación, comparación y análisis de algoritmos para la multiplicación de matrices, enfocado en el comportamiento de la memoria caché. Se incluyen:

- Implementación de dos bucles anidados para ilustrar el efecto de accesos a memoria según el orden de almacenamiento de matrices (row-major).
- Multiplicación clásica con tres bucles anidados.
- Multiplicación por bloques con seis bucles anidados para optimización de caché.
- Evaluación del desempeño para diferentes tamaños de matrices.
- Análisis detallado del movimiento de datos entre memoria principal y caché.
- Uso de herramientas Valgrind (Cachegrind) y KCachegrind para perfilado y análisis de acceso a memoria.

## Contenidos del Repositorio

- `clasica.cpp`: Código fuente C++ de multiplicación clásica de matrices.
- `bloques.cpp`: Código fuente C++ de multiplicación por bloques.
- `script_valgrind.sh`: Script para ejecutar ambos programas con Valgrind y generar perfiles.
- `informe.pdf` / `informe.tex`: Informe completo del proyecto con resultados, análisis y gráficos.
- `README.md`: Este archivo de documentación.

## Implementación

### 1. Dos bucles anidados FOR (Capítulo 2, página 22)

Según el libro base, el acceso a los elementos de una matriz afecta el rendimiento dependiendo de si es por filas (eficiente) o por columnas (ineficiente).

// Acceso eficiente por filas
for (i = 0; i < MAX; i++) {
for (j = 0; j < MAX; j++) {
y[i] += A[i][j] * x[j];
}
}

// Acceso ineficiente por columnas
for (j = 0; j < MAX; j++) {
for (i = 0; i < MAX; i++) {
y[i] += A[i][j] * x[j];
}
}


### 2. Multiplicación clásica de matrices

Tres bucles anidados que calculan cada elemento del resultado sumando productos.

### 3. Multiplicación por bloques

Divide matrices en sub-bloques para mejorar reutilización en caché y disminuir fallos.

## Uso y Ejecución

Compilar los programas (ejemplo usando g++):

g++ -g clasica.cpp -o clasica
g++ -g bloques.cpp -o bloques

Ejecutar con Valgrind Cachegrind para perfilado:
echo 100 | valgrind --tool=cachegrind --cachegrind-out-file=cachegrind_clasica.out ./clasica
echo -e "100\n32" | valgrind --tool=cachegrind --cachegrind-out-file=cachegrind_bloques.out ./bloques

Visualizar con KCachegrind:

kcachegrind cachegrind_clasica.out &
kcachegrind cachegrind_bloques.out &


## Resultados Resumen

- La multiplicación clásica tiene mayor tiempo de ejecución y más fallos de caché.
- La versión por bloques mejora el uso de caché y reduce los tiempos cerca de un 14\% para matrices de gran tamaño.
- El análisis con Valgrind y KCachegrind confirma mejor localidad de referencia usando bloques.

## Análisis del movimiento de datos en caché

- La multiplicación clásica genera muchos fallos por acceso a columnas dispersas en memoria.
- La multiplicación por bloques reduce fallos al trabajar con sub-bloques contiguos que caben en caché, maximizando reutilización.
- Esto optimiza transferencia entre memoria principal y caché, disminuyendo cuellos de botella.



---

Desarrollado por Sergio Ahmed Castillo Sancho

---

Visita el repositorio completo para más detalles y archivos:  
https://github.com/sergioandante/memoria-cache-laboratorio
