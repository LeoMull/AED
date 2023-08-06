#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
struct Stack{
    char val[200];
    int top;
};

bool backspaceCompare(char * s, char * t);

int main(){
   char s[] = "ab#c", t[]= "ad#c";

   if(backspaceCompare(s,t)) printf("True\n");
   else printf("False\n");
}

bool backspaceCompare(char * s, char * t){
    struct Stack pilhaS, pilhaT;
    int len;
    pilhaS.top = -1;
    pilhaT.top = -1;

    for(int i = 0 ; i < strlen(s) ; i++){
        if(isalpha(s[i])){
            pilhaS.top++;
            pilhaS.val[pilhaS.top] = s[i];
        }else{
            pilhaS.top--;
        }
    }
    for(int i = 0 ; i < strlen(t) ; i++){
        if(isalpha(t[i])){
            pilhaT.top++;
               pilhaT.val[pilhaT.top] = t[i];
        }else{
            pilhaT.top--;
        }
    }

    if( strlen(pilhaT.val) == 0 && strlen(pilhaS.val) == 0 ) return true;

    for(int c = 0; c<strlen(pilhaT.val); c++){
        if(pilhaS.val[c] != pilhaT.val[c]) return false;
    }
    return true;
}
