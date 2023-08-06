#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize);

int main()
{
    int *a, b, c, *mat[3]={
        {0,1,0},
        {0,1,1},
        {1,1,1}
        };
    
    b = 3;
    a = kWeakestRows(mat, 3, &b, 2, &c);
    for(int i = 0; i<3; i++){
        printf("%d", a[i]);
    }
    return 0;
}

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize){
    int *cont = malloc (matSize*sizeof(int));
    for(int i = 0 ; i < matSize ; i++){
        for( int j = 0 ; j < *matColSize ; j++ ){
            if(mat[i][j] == 1)
             cont[i]++;
        }
    }
    
    return cont;
}
