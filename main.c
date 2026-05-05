#include "multiplicacion_estandar.h"
#include "strassen.h"
#include "stdio.h"

int main() {
	int n = 4; 

    int **A = crear_matriz(n);
    int **B = crear_matriz(n);
	int **C = crear_matriz(n);
    int **D = crear_matriz(n);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			A[i][j] = i * n + j;
			B[i][j] = i * n + j;
		}
	}

	multiplicacion_estandar(A, B, C, n);
	mostrar(C, n);
	printf("Strassen: \n");
    strassen(A, B, D, n);
	mostrar(D, n);
	
    liberar_matriz(A, n);
    liberar_matriz(B, n);
	liberar_matriz(C, n);
    liberar_matriz(D, n);

    return 0;
}
