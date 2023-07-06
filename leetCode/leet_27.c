#include <stdio.h>

int removeElement(int* nums, int numsSize, int val);

int main(){
    int teste[] = {0,1,2,2,4,3,2};

}

int removeElement(int* nums, int numsSize, int val){
    int cont=0;
    for(int i=0; i<numsSize; i++){
        if(nums[i]==val){
            nums[i] = nums[i+1];
            cont++;
        }
    }
    return numsSize-cont;
}