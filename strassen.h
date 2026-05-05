#ifndef STRASSEN
#define STRASSEN

int** crear_matriz(int n);
void liberar_matriz(int **matriz, int n);
void suma(int** A, int** B, int** C, int n);
void resta(int** A, int** B, int** C, int n);
void split(int** matriz, int** submatriz, int fila_inicio, int columna_inicio, int k);
void combinar(int** matriz, int** submatriz, int fila_inicio, int columna_inicio, int k);
void strassen(int** A, int** B, int** C, int n);
#endif
