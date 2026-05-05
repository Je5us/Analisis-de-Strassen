#include "multiplicacion_estandar.h"
#include <stdio.h>

void multiplicacion_estandar(int** A, int** B, int** C,int n) {	
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < n ; j++){
			for(int k = 0; k < n; k++){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

void mostrar(int** M,int n){
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < n ; j++){
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
}
