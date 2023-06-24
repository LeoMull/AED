/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    
    int *arr = (int*) malloc(2*n*sizeof(int));

    for(int i=0; i<n; i++){
        arr[i*2] = nums[i];
        arr[i*2+1] = nums[n+i];
    }

    *returnSize = numsSize;
    return arr; 
}