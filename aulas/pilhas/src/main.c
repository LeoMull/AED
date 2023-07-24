#include <stdbool.h>
#include <stdio.h>

#define MAX 10

typedef struct Dados{
    int ra;
    char nome[50];
}Aluno;

typedef struct Estrutura{
    Aluno alunos[MAX];
    int topo;
    int base;
    int limite;
}Pilha;

void zera(Pilha *pilha);
bool Full(Pilha *pilha);
bool Empty(Pilha *pilha);
bool Add(Pilha *pilha, Aluno *item);
void Delete(Pilha *pilha, Aluno *aluno);

int main()
{
    

    return 0;
}

void zera(Pilha *pilha){
    (*pilha).topo = 0;
    (*pilha).base = 0;
    (*pilha).limite = MAX;
}
bool Empty(Pilha *pilha){
    return (*pilha).topo == 0;
}
bool Full(Pilha *pilha){
    return (*pilha).topo == MAX;
}
bool Add(Pilha *pilha, Aluno *item){
    if(!Full(pilha)){
        pilha->alunos[pilha->topo] = *item;
        pilha->topo++;
        return true;
    }else {
        return false;
    }
}
void Delete(Pilha *pilha, Aluno *aluno){
    if((*pilha).topo == 0 )
        return ;

    (*pilha).topo--;
    *aluno = (*pilha).alunos[(*pilha).topo];
}
