#include "multiplicacion_estandar.h"
#include "strassen.h"
#include "stdio.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define REPETICIONES 10

static long long elapsedNanoseconds(struct timespec start, struct timespec end) {
    long long seconds = (long long)(end.tv_sec - start.tv_sec);
    long long nanoseconds = (long long)(end.tv_nsec - start.tv_nsec);
    return seconds * 1000000000LL + nanoseconds;
}

//generar matrices con valores aleatorios
void generar_matriz_aleatoria(int** M, int n, int maxValue){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			M[i][j] = rand() % maxValue;
		}	
	}
}

static double medicion_estandard(int** A, int** B,int** C, int n){
	struct timespec start;
	struct timespec end;

	clock_gettime(CLOCK_MONOTONIC, &start);
	multiplicacion_estandar(A, B, C, n);
	clock_gettime(CLOCK_MONOTONIC, &end);

	return (double)elapsedNanoseconds(start, end) / 1000.0;
}

static double medicion_strassen(int** A, int** B, int** C, int n){
	struct timespec start;
	struct timespec end;

	clock_gettime(CLOCK_MONOTONIC, &start);
	strassen(A, B, C, n);
	clock_gettime(CLOCK_MONOTONIC, &end);

	return (double)elapsedNanoseconds(start, end) / 1000.0;
}

int main() {
	srand((unsigned int)time(NULL));
	printf("#n\tEstandar\tStrassen:\n");
	
	for(int n = 2; n <= 1024; n *= 2){
		double estandar_acumulado = 0;
		double strassen_acumulado = 0;

    	int **A = crear_matriz(n);
    	int **B = crear_matriz(n);
		int **C = crear_matriz(n);
    	int **D = crear_matriz(n);
		for(int i = 0; i < REPETICIONES; i++){

			generar_matriz_aleatoria(A, n, 1000);
			generar_matriz_aleatoria(B, n, 1000);
	
			estandar_acumulado += medicion_estandard(A, B, C, n);
			strassen_acumulado += medicion_strassen(A, B, D, n);

		}
		
		liberar_matriz(A, n);
		liberar_matriz(B, n);
		liberar_matriz(C, n);
		liberar_matriz(D, n);
		printf("%d\t%.3f\t%.3f\n", n, estandar_acumulado / REPETICIONES, strassen_acumulado / REPETICIONES);
	}
	return 0;
}
