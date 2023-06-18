/*
*Crie um programa que contenha um array 
*de float contendo 10 elementos. Imprima o
*endereco de cada posicao desse array. 
*/
#include <stdio.h>
 
void escreve(float *a);

int main(){
	float a[10] = {1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9};
	escreve(a);
}
void escreve(float *a){
	for(int i=0; i<sizeof(a); i++){
		printf("Endereco: %d\n", (a+i));
		printf("Valor: %.2f\n", *(a+i));
}
}
