#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * shortestCompletingWord(char * licensePlate, char ** words, int wordsSize);

int main(){
    char c = '2';// licensePlate[] = {'1s3 PSt'}, words[4][7] = {"step","steps","stripe","stepple"};

    if (atoi(c) < 4)
    printf("Teste");

    return 0;
}

char * shortestCompletingWord(char * licensePlate, char ** words, int wordsSize){
    
    for(int i = 0 ; i < wordsSize ; i++ ){  
        for(int j = 0 ; j < strlen(words[wordsSize]) ; j++ ){ //passar por cada palavra
            for(int c = 0 ; c < strlen(words[wordsSize][j]); c++){   //passa por cada letra de words 
                for(int d = 0 ; d < strlen(licensePlate); d++){ //passa por cada letra de licensePlate
                    if( strcmp(licensePlate[d], words[wordsSize][c])){ //comparara a letra de licensePlate com a letra de word se igual retorna 0
                        licensePlate[d] = '0';

                    }   
                }
            }
        }
    }
    for (int i = 0 ; i < wordsSize ; i++){
        if(atoi(words[i]) == 0){
            return words[i];
        }
    }

}
// Ideia 2
//Comparar valor de licensePlate e words com strcmp e guardar o resultado da comparação com menor valor em words
//Depois passar o valor de words para int, a word com o menor valor somado vai ser a escolhida


// Ideia 1
//comparara cada letra de cada palavra do words com o plate,
//se as letras forem iguais a letra no words sera mudada para 0. 
//Se for 0 colocar 0 no licenseplate
//Se for difernete de zero não muda
//Ao final se licensePlate for somente números a palavra é válida

/*char * shortestCompletingWord(char * licensePlate, char ** words, int wordsSize){
    //Tentar comparar palavras do words com licensePlate com strcmp se 

   
    for(int i = 0 ; i < strlen(licensePlate) ; i++ ){ // passar pela placa
        for(int j = 0; j < wordsSize ; j++){      // passar pelas palavras
            for(int c = 0 ; c < strlen(words[wordsSize]) ; c++){// passar pelas letras de cada palavras
                
            }
        }
    }
    return licensePlate;
    */
}

/*
strlen para diferenciar tamanho dentre válidos
*/