#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target);

int main()
{
    int nums[] = { 0,2,3,5,7,8 };

    printf("Resultado: %d \n",searchInsert( nums,  6, 2));
    printf("Resultado: %d \n",searchInsert( nums,  6, -2));
    printf("Resultado: %d \n",searchInsert( nums,  6, 4));
    printf("Resultado: %d \n",searchInsert( nums,  6, 10));

    return 0;
}

int searchInsert(int* nums, int numsSize, int target){
    if( nums[0] >= target )
        return 0;

    for( int i = 1 ; i < numsSize ; i++ ){
        if ( nums[i] == target ){
            return i;
        } else if ( nums[i] > target &&  nums[i-1] < target){
                    return i;
               }
    }
    return numsSize;
}