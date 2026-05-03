#include "multiplicacion_estandar.h"
#include <stdio.h>

void multiplicacion_estandar(int A[][N], int B[][N], int C[][N]) {	
	for(int i = 0; i < N ; i++){
		for(int j = 0; j < N ; j++){
			for(int k = 0; k < N; k++){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

void mostrar(int M[][N]){
	for(int i = 0; i < N ; i++){
		for(int j = 0; j < N ; j++){
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
}
