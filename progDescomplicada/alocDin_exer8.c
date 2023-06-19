#include <stdio.h>
#include <stdlib.h>
int main(){
	int *p, cont2=0,cont=0;
	p = (int *) calloc(1500, sizeof(int));

	for(int i =0; i<1500; i++){
		if(*(p+i)==0){
			cont++;	
		}	
	cont2++;
	}

	printf("Número de espaços alocados %d com 0\n", cont);
	
	for(int i=0; i<1500; i++){
		p[i]=i;
	}
	for(int i=0; i<10; ++i){
		printf("Maiores números = %d | Menores números = %d \n", p[1499-i], p[i]);
	}
	free(p);
}
