#include "strassen.h"
#include <stdio.h>
#include <stdlib.h>

//funciones para la memoria dinamica
int** crear_matriz(int n){
	int** matriz = malloc(n * sizeof(int *));
	for(int i = 0;i < n; i++)
		matriz[i] = malloc(n * sizeof(int));
	return matriz;
}

void liberar_matriz(int **matriz, int n){
	for(int i = 0; i < n; i++)
		free(matriz[i]);
	free(matriz);
}

void suma(int** A, int** B, int** C, int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			C[i][j] = A[i][j] + B[i][j];
		}
	}
}

void resta(int** A, int** B, int** C, int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			C[i][j] = A[i][j] - B[i][j];
		}
	}
}

void split(int** matriz, int** submatriz, int fila_inicio, int columna_inicio, int k){
	for(int i = 0; i < k; i++){
		for(int j = 0; j < k; j++){
			submatriz[i][j] = matriz[fila_inicio + i][columna_inicio + j];
		}
	}	
}

void combinar(int** matriz, int** submatriz, int fila_inicio, int columna_inicio, int k){
	for(int i = 0; i < k; i++){
		for(int j = 0; j < k; j++){
			matriz[fila_inicio + i][columna_inicio + j] = submatriz[i][j];
		}
	}	
}

void strassen(int** A, int** B, int** C, int n){
	if(n == 1){
		C[0][0] = A[0][0] * B[0][0];
		return;
	}
	int k = n/2;
	
	//submatrices ahora en el heap
	int **a = crear_matriz(k);
	int **b = crear_matriz(k);
	int **c = crear_matriz(k);
	int **d = crear_matriz(k);
	int **e = crear_matriz(k);
	int **f = crear_matriz(k);
	int **g = crear_matriz(k);
	int **h = crear_matriz(k);

	//llenar sumbatrices
	split(A, a, 0, 0, k);
	split(A, b, 0, k, k);
	split(A, c, k, 0, k);
	split(A, d, k, k, k);

	split(B, e, 0, 0, k);
	split(B, f, 0, k, k);
	split(B, g, k, 0, k);
	split(B, h, k, k, k);
	
	//Matrices temporales para calculos intermedios ahora dinamicos
	int **T1 = crear_matriz(k);
	int **T2 = crear_matriz(k);

	//los 7 productos P1-P2-P3-...-P7 ahora dinamicos
	int **P1 = crear_matriz(k);
	int **P2 = crear_matriz(k);
	int **P3 = crear_matriz(k);
	int **P4 = crear_matriz(k);
	int **P5 = crear_matriz(k);
	int **P6 = crear_matriz(k);
	int **P7 = crear_matriz(k);

	//Calculo para los Productos:
	//P1 = a*(f - h)
	resta(f, h, T1, k);
	strassen(a, T1, P1, k);

	//P2 = (a + b)*h
	suma(a, b, T1, k);
	strassen(T1, h, P2, k);

	//P3 = (c + d)*e
	suma(c, d, T1, k);
	strassen(T2, e, P3, k);

	//P4 = d*(g - e)
	resta(g, e, T1, k);
	strassen(d, T1, P4, k);

	//P5 = (a + d)*(e + h)
	suma(a, d, T1, k);
	suma(e, h, T2, k);
	strassen(T1, T2, P5, k);

	//P6 = (b - d)*(g + h)
	resta(b, d, T1, k);
	suma(g, h, T2, k);
	strassen(T1, T2, P6, k);

	//P7 = (a - c)*(e + f)}
	resta(a, c, T1, k);
	suma(e, f, T2, k);
	strassen(T1, T2, P7, k);

	//cuadrantes de la matriz resultante
	int **r = crear_matriz(k);
	int **s = crear_matriz(k);
	int **t = crear_matriz(k);
	int **u = crear_matriz(k);

	//Calculo para los Cuadrantes:
	//r = P5 + P4 - P2 + P6
	suma(P5, P4, T1, k);
	suma(P2, P6, T2, k);
	resta(T1, T2, r, k);

	//s = P1 + P2
	suma(P1, P2, s, k);

	//t = P3 + P4
	suma(P3, P4, t, k);

	//u = P5 + P1 - P3 - P7 = (P5 + P1) - (P3 + P7)
	suma(P5, P1, T1, k);
	suma(P3, P7, T2, k);
	resta(T1, T2, u, k);
	//combinar los cuadrantes en al matriz C
	combinar(C, r, 0, 0, k);
	combinar(C, s, 0, 0, k);
	combinar(C, t, 0, 0, k);
	combinar(C, u, 0, 0, k);
	
	//liberar las sub-matrices
	liberar_matriz(a,k);
	liberar_matriz(b,k);
	liberar_matriz(c,k);
	liberar_matriz(d,k);
	liberar_matriz(e,k);
	liberar_matriz(f,k);
	liberar_matriz(g,k);
	liberar_matriz(h,k);
	
	//liberar las matrices temporales
	liberar_matriz(T1,k);
	liberar_matriz(T2,k);

	//liberar las matrices de los productos
	liberar_matriz(P1,k);
	liberar_matriz(P2,k);
	liberar_matriz(P3,k);
	liberar_matriz(P4,k);
	liberar_matriz(P5,k);
	liberar_matriz(P6,k);
	liberar_matriz(P7,k);

	//liberar las matrices de los cuadrantes
	liberar_matriz(r,k);
	liberar_matriz(s,k);
	liberar_matriz(t,k);
	liberar_matriz(u,k);
}
