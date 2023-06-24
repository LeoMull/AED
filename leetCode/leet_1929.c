#include <stdio.h>
#include <stdlib.h>

int* getConcatenation(int* nums, int numsSize, int* returnSize);

int main(){
    int *arr,vr,nums[] = {1,2,3};
    
    arr = getConcatenation(nums, 3, &vr); 

    for(int i =0; i<vr; i++){
        printf("%d\n", *(arr+i));
    }
}

int* getConcatenation(int* nums, int numsSize, int* returnSize){
    int *arr = (int*)malloc(2*numsSize*sizeof(int));
    int tam = numsSize-1;

    for(int i=0; i<numsSize; i++){
        arr[i] = nums[i];
        arr[numsSize+i] = nums[i];
    }
    *returnSize = numsSize*2;
    return arr;
}