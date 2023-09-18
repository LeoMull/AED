int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int retornoS = 0, **retorno, **retornoCol;
    retorno = malloc(intervalsSize*sizeof(int));
    *retorno = malloc(2*sizeof(int));

    retornoCol = malloc(3*sizeof(int));
    *retornoCol = malloc(2*sizeof(int));
    for(int i = 0; i<intervalsSize; i++){
        for(int j = i+1; j < intervalsSize; j++){
            if(intervals[i][1] <= intervals[j][0]){
                retorno[i][0] = intervals[i][0];
                retorno[i][1] = intervals[j][1];
                retornoS++;
                retornoCol[0][0] = 2;
                break;
            }
        }
        /*
        if(retorno[i] == NULL){
            retorno[i] = malloc(2*sizeof(int));
            retorno[i][0] = intervals[i][0];
            retorno[i][0] = intervals[i][0];
            retornoS++;
        }*/
    }

   returnColumnSizes = retornoCol;
    *returnSize = intervalsSize - 1;
    return retorno;
}
//fazer for duplo comparando todas as strings 
//se a posição 1 da string for maior que a posição 0 da outra string 
//elas devem fazer merge 
//dificuldade com ponteiro para ponteiro / alocação dinamica de matriz