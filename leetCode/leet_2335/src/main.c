#include <stdio.h>

int fillCups( int* amount, int amountSize );

int main(){
    int amount1[] = { 5, 4, 4 }, amount2[] = { 1, 2, 3 }, amount3[] = { 5, 0, 0 } ;

    printf("%d\n", fillCups( amount1, 3 ));
    printf("%d\n", fillCups( amount2, 3 ));
    printf("%d\n", fillCups( amount3, 3 ));
    
    return 0;
}
/*
=======================
fillCups
    Retorna o numero de segundos que leva para encher os copos
=======================
*/

int fillCups( int* amount, int amountSize ){
    int total = 0 ;
    while( amount[0] && amount[1] ){
        if( amount[0]+amount[1] <= amount[2] ) break;
        amount[0]--;
        amount[1]--;
        total++;
    }
    if( amount[0] >= amount[1] ){
        while( amount[0] && amount[2] ){
            amount[0]--;
            amount[2]--;
            total++;
        }
         while( amount[1] && amount[2] ){
            amount[1]--;
            amount[2]--;
            total++;
        }       
    }else{
        while( amount[1] && amount[2] ){
            amount[1]--;
            amount[2]--;
            total++;
        }
        while( amount[0] && amount[2] ){
            amount[0]--;
            amount[2]--;
            total++;
        }
    }
    if( amount[0] ) return total += amount[0];
    if( amount[1] ) return total += amount[1];
    if( amount[2] ) return total += amount[2];

    return total;
}