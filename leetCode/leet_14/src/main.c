#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * longestCommonPrefix(char ** strs, int strsSize);

int main(int argc, char const *argv[])
{
    char *strs[] = {"flower","flow","flight"},
    *strs2[] = {"car", "dog", "carnival"}, *strs3[] = {"pattern","pattent","pat"};

    printf("%s\n",longestCommonPrefix(strs, 3));

    printf("%s\n",longestCommonPrefix(strs2, 3));

    printf("%s\n",longestCommonPrefix(strs3, 3));

    return 0;
}

char * longestCommonPrefix(char ** strs, int strsSize){
    int c = 0;
    char *subS = calloc (strlen(strs[0]),sizeof(char));

    strcpy(subS,strs[0]);
    
    for(int i = 1 ; i < strsSize ; i++){
        while(subS[c] == strs[i][c] || strlen(subS) == c){
            c++;
        }

        if( c == 0 ) return "";
        
        memcpy(subS, strs[i], c);
        subS[c] = '\0';
        c = 0;
    }

    return subS;
}
/*
Funciona apenas caso 1

char * longestCommonPrefix(char ** strs, int strsSize){
    int c = 0;
    char *subS = malloc (sizeof(char)*strsSize);

    strcpy(subS,strs[1]);
    
    for(int i = 0 ; i < strsSize ; i++){
        while(subS[c] == strs[i][c]){
            c++;
        }
        memcpy(subS, strs[i], c);
    }
    
    return subS;
}*/