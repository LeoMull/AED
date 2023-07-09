/*
LeetCode 748
Given a string licensePlate and an array of strings words, find the shortest completing word in words.
A completing word is a word that contains all the letters in licensePlate. 
Ignore numbers and spaces in licensePlate, and treat letters as case insensitive. 
If a letter appears 
more than once in licensePlate, then it must appear in the word the same number of times or more.
For example, if licensePlate = "aBc 12c", then it contains letters 'a', 'b' (ignoring case), and 'c' twice.
Possible completing words are "abccdef", "caaacab", and "cbca".

Return the shortest completing word in words. It is guaranteed an answer exists. 
If there are multiple shortest completing words, return the first one that occurs in words.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* shortestCompletingWord(char *licensePlate, char **words, int wordsSize);

int PalavraValida(char *word, char *licensePlate);

int main(){
    int wordsSize = 4, wordsSize2 = 4, wordsSize3 = 3;
    char licensePlate[] = {"1s3 pst"}, *words[] = {"step","steps","stripe","stepple"};
    char licensePlate2[] = {"1s3 456"}, *words2[] = {"looks","pest","stew","show"};
    char licensePlate3[] = {"aBc 12c"}, *words3[] = {"abccdef", "caaacab", "cbca"};
     
    printf("%s\n",shortestCompletingWord(licensePlate, words, wordsSize));
    printf("%s\n",shortestCompletingWord(licensePlate2, words2, wordsSize2));
    printf("%s\n",shortestCompletingWord(licensePlate3, words3, wordsSize3));

    return 0;
}

/*
====================
PalavraValida
Teste se a palavra é válida, se for válida retorna 1, se não retorna 0
====================
*/
int PalavraValida(char *word, char *licensePlate) {
    char aux[8];
    char *ptr;

    strcpy(aux, licensePlate);

    for (int i = 0; i < strlen(word); i++) {
        ptr = strchr(aux, word[i]);
        if (ptr != NULL) {
            *ptr = '0';
        }
    }

    for (int i = 0; i < strlen(aux); i++) {
        if (isalpha(aux[i])) {
            return 0;
        }
    }

    return 1;
}

/*
====================
shortestCompletingWord
Acha a palavra válida mais curta e retorna ela, após passar por todas as possibilidades
====================
*/
char* shortestCompletingWord(char *licensePlate, char **words, int wordsSize) {
    int tamPalavraMaisCurta = 1000;
    char *palavraMaisCurta = NULL;

    for (int i = 0; i < strlen(licensePlate); i++) {
        if (isalpha(licensePlate[i])) {
            licensePlate[i] = tolower(licensePlate[i]);
        }
    }

    for (int i = 0; i < wordsSize; i++) {
        if (strlen(words[i]) < tamPalavraMaisCurta && PalavraValida(words[i], licensePlate)) {
            tamPalavraMaisCurta = strlen(words[i]);
            palavraMaisCurta = words[i];
        }
    }

    return palavraMaisCurta;
}


