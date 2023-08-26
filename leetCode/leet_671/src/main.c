#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

int min = 0, min2 = 0, max=0;

void achaMenor(struct TreeNode* root);
void achaMaior(struct TreeNode* root);
int findSecondMinimumValue(struct TreeNode* root);
struct TreeNode* createNode(int val);
void endTree(struct TreeNode* root);
void printTree(struct TreeNode* root);

int main(int argc, char const *argv[])
{
    struct TreeNode *root1 = createNode(2);
    struct TreeNode *root2 = createNode(2);
    struct TreeNode *root3 = createNode(1);
    
    root1->left = createNode(2);
    root1->right = createNode(5);
    root1->right->left = createNode(5);
    root1->right->right = createNode(7);
    printf("Teste 1: %d\n",findSecondMinimumValue(root1));
    printTree(root1);


    root2->left = createNode(2);
    root2->right = createNode(2);
    printf("\n\nTeste 2: %d\n",findSecondMinimumValue(root2));
    printTree(root2);


    root3->left = createNode(1);
    root3->right = createNode(2);
    root3->right->left = createNode(5);
    root3->right->right = createNode(10);
    printf("\n\nTeste 1: %d\n",findSecondMinimumValue(root3));
    printTree(root3);

    return 0;
} 
/*
===================
createNode
cria e retorna um nó que será utilizado na árvore
===================
*/
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/*
===================
printTree
Passa em pós ordem pela árvore escrevendo e dando free na célula
Foi criada apenas para teste por isso faz as duas coisas
===================
*/
void printTree(struct TreeNode* root) {
    if (root) {
        printTree(root->left);
        printTree(root->right);
        printf("# %d #", root->val);
        free(root);
    }
}
/*
===================
achaMenor
Passa por todos os nós da árvore e guarda os dois menores valores em variáveis globais
===================
*/
void achaMenor(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    if(root->val < min && min2 != root->val){
        min2 = min;
        min = root->val;
    }else if(root->val < min2 && min != root->val){
        min2 = root->val;
    }
    achaMenor(root->left);
    achaMenor(root->right);
}
/*
===================
achaMaior
Passa por todos os nós da árvore e guarda o maior valor em uma varável global
===================
*/
void achaMaior(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    if(max < root->val){
        max = root->val;
    }
    achaMaior(root->left);
    achaMaior(root->right);
}
/*
===================
findSecondMinimumValue
Retorna o segundo menor valor de uma árvore
===================
*/
int findSecondMinimumValue(struct TreeNode* root){
    max = 0;
    min = 0;
    min2 = 0;
    achaMaior(root);

    min = max;
    
    achaMenor(root);

    if(min2 == 0){ 
        return -1;
    }

    return min2;
}