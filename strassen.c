#include "strassen.h"
#include <stdio.h>

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

void strassen(int A[][N], int B[][N], int C[][N]){
}
