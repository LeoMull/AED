#include <stdio.h>
#include <stdlib.h>
int maxProfit(int* prices, int pricesSize);

int main(){
    int a[] = {7,1,5,3,6,4}, b = 6, c[] = {2,1,4}, d[]={2,4,1};

    printf("%d\n", maxProfit(a,b));
//    printf("%d\n", maxProfit(c,3));
    printf("%d\n", maxProfit(d,3));

    return 0;
}


/*
passa 198/212
int maxProfit(int* prices, int pricesSize){
    int menorValorIndice = 0, * lucro, maiorLucro = 0;
    
    lucro = calloc(pricesSize, sizeof(int));

    for(int i = 0 ; i < pricesSize ; i++){
        for(int j = 0 ; j < pricesSize ; j++){
            if(lucro[i] < prices[j] - prices[i] && i < j){
                lucro[i] = prices[j] - prices[i];

            }
        }
        if( maiorLucro < lucro[i]){
            maiorLucro = lucro[i];
        }
    }

    return maiorLucro;
}
*/

/*
int maxProfit(int* prices, int pricesSize){
    int menorValor = 0, menorValorIndice = 0, maiorLucro = 0;

    menorValor = prices[0];

    for(int i = 0 ; i < pricesSize ; i++){
        if (prices[i] <= menorValor){
                menorValor = prices[i];
            menorValorIndice = i;
        }
    }

    if( menorValorIndice == pricesSize-1 ) return 0;

    for( int j = menorValorIndice ; j < pricesSize ; j++){

        if( (prices[j] - menorValor) > maiorLucro ){
            maiorLucro = prices[j] - menorValor;
        }
    }
    return maiorLucro;
}
*/