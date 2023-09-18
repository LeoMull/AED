#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b);
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes);

int main() {
    int intervals1[][2] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    int* returnColumnSizes1;
    int returnSize1;

    int* intervals1Ptr[4]; 
    for (int i = 0; i < 4; i++) {
        intervals1Ptr[i] = intervals1[i]; 
    }

    int** result1 = merge(intervals1Ptr, 4, NULL, &returnSize1, &returnColumnSizes1);

    printf("Teste 1:\n");
    for (int i = 0; i < returnSize1; i++) {
        printf("[%d, %d]\n", result1[i][0], result1[i][1]);
        free(result1[i]);
    }
    free(result1);
    free(returnColumnSizes1);


    int intervals2[][2] = {{1, 4}, {4, 5}};
    int* returnColumnSizes2;
    int returnSize2;

    int* intervals2Ptr[2];
    for (int i = 0; i < 2; i++) {
        intervals2Ptr[i] = intervals2[i];
    }

    int** result2 = merge(intervals2Ptr, 2, NULL, &returnSize2, &returnColumnSizes2);

    printf("\nTeste 2:\n");
    for (int i = 0; i < returnSize2; i++) {
        printf("[%d, %d]\n", result2[i][0], result2[i][1]);
        free(result2[i]);
    }
    free(result2);
    free(returnColumnSizes2);


    int intervals3[][2] = {{1, 4}};
    int* returnColumnSizes3;
    int returnSize3;

    int* intervals3Ptr[1]; 
    intervals3Ptr[0] = intervals3[0]; 

    int** result3 = merge(intervals3Ptr, 1, NULL, &returnSize3, &returnColumnSizes3);

    printf("\nTeste 3:\n");
    for (int i = 0; i < returnSize3; i++) {
        printf("[%d, %d]\n", result3[i][0], result3[i][1]);
        free(result3[i]);
    }
    free(result3);
    free(returnColumnSizes3);

    return 0;
}

int cmpfunc(const void *a, const void *b){
    return (**(int**)a - **(int**)b);
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    
    if(intervalsSize == 1){
        *returnSize = 1;
        *returnColumnSizes = malloc(1*sizeof(int));
        (*returnColumnSizes)[0] = 2;
        return intervals;
    }
    if(intervalsSize == 0){
        return intervals;
    }

    qsort(intervals,intervalsSize, sizeof(int*), cmpfunc);

    int rSize = 0, intervalsSizeOrigin = intervalsSize, c = 0;
    for (int i = 0; i < intervalsSize - 1; i++) { 
        if (intervals[i][1] >= intervals[i + 1][0]) { 

            if (intervals[i][1] < intervals[i + 1][1]) {
                intervals[i][1] = intervals[i + 1][1];
            } else {
                intervals[i + 1][1] = intervals[i][1];
            }

            for (int j = i + 1; j < intervalsSize - 1; j++) {
                intervals[j][0] = intervals[j + 1][0];
                intervals[j][1] = intervals[j + 1][1];
            }

            intervalsSize--; 
            i--;
        }
    }
    rSize = intervalsSize;

    int ** ret = malloc(rSize * sizeof(int*));
    *returnSize = rSize;
    *returnColumnSizes = malloc(rSize * sizeof(int));

    for (int i = 0; i < rSize; i++){
        (*returnColumnSizes)[i] = 2;
        
        ret[i] = malloc(2 * sizeof(int));
        ret[i][0] = intervals[i][0];
        ret[i][1] = intervals[i][1];
    }
    return ret;
}