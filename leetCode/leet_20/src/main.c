/*
Apenas para adicionar o código do problema
*/

bool isValid(char *s){
    char pilha[strlen(s)];
    int top = -1;
    for(int i = 0; i<strlen(s) ; i++){
        switch(s[i]){
            case '(':
                pilha[++top] = '(';
                break;

            case ')':
                if(top >= 0 && pilha[top] == '(')
                    top--;
                else
                    return false;
                break;
            case '[':
                pilha[++top] = '[';
                break;
                
            case ']':
                if(top >= 0 && pilha[top] == '[')
                    top--;
                else
                    return false;
                break;
            case '{':
                pilha[++top] = '{';
                break;
                
            case '}':
                if(top >= 0 && pilha[top] == '{')
                    top--;
                else
                    return false;
                break;
        }
    }
    if(top == -1){
        return true;
    }
    return false;
}