#ifndef STRASSEN
#define STRASSEN

#define N 4

void suma(int A[][N], int B[][N], int C[][N]);
void resta(int A[][N], int B[][N], int C[][N]);
void split(int matriz[][N], int submatriz[][N], int fila_inicio, int columna_inicio, int k);
void combinar(int matriz[][N], int submatriz[][N], int fila_inicio, int columna_inicio, int k);
void strassen(int A[][N], int B[][N], int C[][N], int N);

#endif
