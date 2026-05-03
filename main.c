#include "multiplicacion_estandar.h"

int main(){
	int A[N][N] = {{1,0,0},{0,1,0},{0,0,1}};
	int B[N][N] = {{1,2,3},{4,5,6},{7,8,9}};
	int C[N][N] = {0};
	
	multiplicacion_estandar(A, B, C);
	mostrar(C);
	
	return 0;
}
