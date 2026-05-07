# Análisis Empírico: Multiplicación de Matrices Estándar vs. Strassen Híbrido

Análisis comparativo del rendimiento entre el algoritmo de multiplicación de matrices estándar **O(n³)** y una implementación optimizada del algoritmo de Strassen **O(n^2.81)**. El objetivo es determinar empíricamente el **punto de cruce (n₀)** donde la eficiencia asintótica de Strassen supera el costo de su gestión recursiva.

---

## Algoritmos Implementados

### Algoritmo Estándar
Implementación de triple bucle iterativo con complejidad cúbica O(n³).

### Strassen Híbrido
- Reducción de 8 a 7 multiplicaciones recursivas por nivel.
- **Optimización clave:** caso base híbrido en `n ≤ 64`. Al alcanzar este umbral, el algoritmo conmuta al método estándar para evitar el *overhead* de la gestión de memoria y la recursión en matrices pequeñas.

---

## Estructura del Repositorio

```
.
├── main.c                     # Lógica experimental, muestreo y toma de tiempos
├── multiplicacion_estandar.c  # Implementación del algoritmo O(n³)
├── multiplicacion_estandar.h  # Cabeceras y prototipos del algoritmo estándar
├── strassen.c                 # Lógica de Strassen, división de matrices y caso base híbrido
├── strassen.h                 # Definiciones, gestión de memoria dinámica y prototipos
├── Makefile                   # Automatización de compilación y generación de gráficas
└── README.md
```

---

## Requisitos del Sistema

| Herramienta | Descripción |
|-------------|-------------|
| **GCC** | GNU Compiler Collection con soporte para C11 |
| **GNU Make** | Sistema de automatización de compilación |
| **Gnuplot** | Generación de gráficas (visualización de datos) |
| **Linux** | Probado y desarrollado en Fedora |

---

## Uso

### 1. Compilar

```bash
make
```

Genera el ejecutable `programa`.

### 2. Ejecutar y generar gráficas

```bash
make plot
```

Ejecuta el experimento completo, guarda los resultados en `resultados.dat` y genera el análisis visual.

### 3. Limpiar archivos generados

```bash
make clean
```

Elimina archivos objeto y binarios.

---

## Metodología

- **Métricas de tiempo:** `clock_gettime` con `CLOCK_MONOTONIC` para precisión de nanosegundos (reportado en microsegundos).
- **Tratamiento de ruido:** cada punto en la gráfica representa el promedio de **10 ejecuciones independientes**.

---

## Interpretación de Resultados

La gráfica generada presenta:

- **Ejes logarítmicos:** facilitan la visualización del crecimiento asintótico y la comparación de pendientes entre ambos algoritmos.
- **Punto de cruce (n₀):** resalta el umbral donde la curva de Strassen supera a la estándar. En esta implementación se observa ventaja a partir de `n = 64`.
- **Nota sobre memoria:** Strassen requiere un uso más intensivo de memoria dinámica por las submatrices intermedias, lo cual es el principal factor que determina el punto de cruce empírico.

---

## Autor

**Jesús Gustavo Pérez Villasante**  
Universidad Nacional de San Agustín — UNSA
