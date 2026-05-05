#include "strassen.h"
#include <stdio.h>
#include <stdlib.h>

void suma(int A[][N], int B[][N], int C[][N]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			C[i][j] = A[i][j] + B[i][j];
		}
	}
}

void resta(int A[][N], int B[][N], int C[][N]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			C[i][j] = A[i][j] - B[i][j];
		}
	}
}

void split(int matriz[][N], int submatriz[][N], int fila_inicio, int columna_inicio, int k){
	for(int i = 0; i < k; i++){
		for(int j = 0; j < k; j++){
			submatriz[i][j] = matriz[fila_inicio + i][columna_inicio + j];
		}
	}	
}

void combinar(int matriz[][N], int submatriz[][N], int fila_inicio, int columna_inicio, int k){
	for(int i = 0; i < k; i++){
		for(int j = 0; j < k; j++){
			matriz[fila_inicio + i][columna_inicio + j] = submatriz[i][j];
		}
	}	
}

void strassen(int A[][N], int B[][N], int C[][N], int k){
	if(N == 1){
		C[0][0] = A[0][0] * B[0][0];
		return;
	}
	int k = N/2;
	
	//submatrices
	int a[k][k];
	int b[k][k];
	int c[k][k];
	int d[k][k];
	int e[k][k];
	int f[k][k];
	int g[k][k];
	int h[k][k];

	//llenar sumbatrices
	split(A, a, 0, 0, k);
	split(A, b, 0, k, k);
	split(A, c, k, 0, k);
	split(A, d, k, k, k);

	split(B, e, 0, 0, k);
	split(B, f, 0, k, k);
	split(B, g, k, 0, k);
	split(B, h, k, k, k);
	
	//Matrices temporales para calculos intermedios
	int T1[k][k]; 
	int T2[k][k];

	//los 7 productos P1-P2-P3-...-P7
	int P1[k][k];
	int P2[k][k];
	int P3[k][k];
	int P4[k][k];
	int P5[k][k];
	int P6[k][k];
	int P7[k][k];

	//Calculo para los Productos:
	//P1 = a*(f - h)
	resta(f, h, T1);
	strassen(a, T1, P1, k);

	//P2 = (a + b)*h
	suma(a, b, T1);
	strassen(T1, h, P2, k);

	//P3 = (c + d)*e
	suma(c, d, T1);
	strassen(T2, e, P3, k);

	//P4 = d*(g - e)
	resta(g, e, T1);
	strassen(d, T1, P4, k);

	//P5 = (a + d)*(e + h)
	suma(a, d, T1);
	suma(e, h, T2);
	strassen(T1, T2, P5, k);

	//P6 = (b - d)*(g + h)
	resta(b, d, T1);
	suma(g, h, T2);
	strassen(T1, T2, P6, k);

	//P7 = (a - c)*(e + f)}
	resta(a, c, T1);
	suma(e, f, T2);
	strassen(T1, T2, P7, k);

	//cuadrantes de la matriz resultante
	int r[k][k];
	int s[k][k];
	int t[k][k];
	int u[k][k];

	//Calculo para los Cuadrantes:
	//r = P5 + P4 - P2 + P6
	suma(P5, P4, T1);
	suma(P2, P6, T2);
	resta(T1, T2, r);

	//s = P1 + P2
	suma(P1, P2, s);

	//t = P3 + P4
	suma(P3, P4, t);

	//u = P5 + P1 - P3 - P7 = (P5 + P1) - (P3 + P7)
	suma(P5, P1, T1);
	suma(P3, P7, T2);
	resta(T1, T2, u);
	//combinar los cuadrantes en al matriz C
	combinar(C, r, 0, 0, k);
	combinar(C, s, 0, 0, k);
	combinar(C, t, 0, 0, k);
	combinar(C, u, 0, 0, k);
}
