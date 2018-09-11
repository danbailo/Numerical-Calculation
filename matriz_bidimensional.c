#include <stdio.h>
#include <stdlib.h>

int* soma_matriz(int *a, int *b){
	int *c = (int*)malloc(sizeof(int)*9);
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			c[(i*3)+j] = a[(i*3)+j] + b[(i*3)+j];
		}
	}
	return c;
}
void print_matriz(int *a){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			printf("%i ",a[(i*3)+j]);
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[]){
	
	int matrizA[3][3] = {{2,3,-1},{0,-2,-1},{0,0,5}};
	int matrizB[3][3] = {{5,2,-1},{5,-6,-1},{7,2,5}};

	int *matrizC = soma_matriz((int*)matrizA,(int*)matrizB);

	print_matriz((int*)matrizA);
	printf("\n");
	print_matriz((int*)matrizB);
	printf("\n");
	print_matriz((int*)matrizC);
	
	return 0;
}