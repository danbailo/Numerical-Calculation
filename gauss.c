#include <stdio.h>
#include <string.h>
#define TAM 3


void print_matriz(double *a,int tam){
	for(int i=0;i<tam;i++){
		for(int j=0; j<tam; j++){
			printf("%.3lf ",a[(i*3)+j]);
		}
		printf("\n");
	}	
	printf("\n");
}

void print_vetor(double *a,int tam){
	for(int i=0;i<tam;i++){
		printf("%.3lf\n",a[(i)]);
	}
	printf("\n");
}

void vetor_escalar(double *a,double m){
	for(int i=0; i < TAM; i++){
		a[i] *=m;
	}
}

void vetor_soma(double *a,double *b){
	for(int i=0; i < TAM; i++){
		(a[i])+=b[i];
	}	
}

void vetor_troca(double *a, double *b){
	for(int i=0; i < TAM; i++){
		double c = (a[i]);
		(a[i]) = (b[i]);
		(b[i]) = c;
	}	
}

int main(int argc, char const *argv[]){
	printf("\n");
	// A é uma matriz n x n;
	// x é um vetor n x 1;
	// b é um vetor n x 1;
	int k,i,j;
	// double a[TAM][TAM] = {{3,2,4},{1,1,2},{4,3,-2}};
	double a[TAM][TAM] = {{1,2,1},{1,-3,5},{2,-1,3}};
	// double a[TAM][TAM] = {{1,1,0},{1,0,1},{0,0,1}};
	// double b[TAM] = {1,2,3};
	double b[TAM] = {12,1,10};
	double x[TAM] = {0,0,0};

	double m,s,c;


	print_matriz((double*)a,TAM);

	print_vetor((double*)b,TAM);

	// printf("a[0][0]:%lf\n",a[0][0]);
	// printf("a[2][2]:%lf\n",a[2][2]);

	{// for(k = 0; k < TAM; k++){
		// 	for(i = k+1; i < TAM; i++){
		// 		m = (a[i][k])/(a[k][k]);
		// 		a[i][k] -= m*a[k][k];
		// 		b[i] -= m*b[k];
		// 		for(j = k+1; j < TAM; j++){
		// 			// printf("b[%d]:%lf\n",i,b[i]);
		// 			a[i][j] -= m*a[k][j];
		// 			// printf("a[%d][%d]:%lf\n",i,j,a[i][j]);
		// 		}
		// 	}
		// 	// printf("k:%d\n",k);
		// 	// printf("i:%d\n",i);
		// 	// printf("j:%d\n",j);
		// }
	}

	double temp[TAM];


	for(i = 0; i<TAM; i++){
		double pivo ;
		pivo = a[i][i];
		if(pivo == 0.0){
			printf("troca\n");
			if(i== TAM-2){
				printf("det é 0");
				return -1;
			}
			vetor_troca((double *)a[i],(double *)a[i+1]);
			c = b[i];
			b[i] = b[i+1];
			b[i+1] = c;
			pivo = a[i][i];
		}
		vetor_escalar((double *)a[i],1/pivo);
		printf("oi\n");
		b[i] /= pivo;
		for(j = i+1; j<TAM; j++){
			memcpy(temp,a[i],sizeof(double)*TAM);
			vetor_escalar((double *)temp,-a[j][i]);
			b[j] -= a[j][i]*b[i];
			vetor_soma((double *)a[j],(double *)temp);
		}
	}

	print_matriz((double*)a,TAM);

	print_vetor((double*)b,TAM);

	// se a matriz e 3x3, entao o index maior é 2
	// printf("a[2][2]: %lf\n",(a[2][2]));
	// printf("b[2]: %lf\n",(b[2]));
	
	// x[TAM-1] = b[TAM-1]/a[TAM-1][TAM-1];

	for(int k = (TAM-1); k >= 0; k--){
		s = b[k];
		for(int j = k; j<TAM; j++){
			s -= (a[k][j])*(x[j]);
		}
		x[k] = s/a[k][k];
	}

	printf("\n");
	print_vetor(x,TAM);

	return 0;
}