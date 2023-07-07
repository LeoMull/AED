#include <stdio.h>

int singleNumber(int* nums, int numsSize);

int main()
{
    int m1[] = {1}, m2[] = {4,2,1,2,1}, m3[] = {2,2,1}, m4[] = {1,0,1};
    printf("%d\n",singleNumber(m1, 1));
    printf("%d\n",singleNumber(m2, 5));
    printf("%d\n",singleNumber(m3, 3));
    printf("%d\n",singleNumber(m4, 3));

    return 0;
}

int singleNumber(int* nums, int numsSize){
    /*
        O operador '^=' faz uma XOR bit a bit com o valor do comparador
        Então se o valor do nums aparecer duas o comparador volta a ser zero,
        senão mantem o valor que não se repetiu
    */
    int comparador = 0;

    for(int i=0;i<numsSize;i++){
        comparador ^=nums[i];
    }
    return comparador;
        /*
        Minha tentativa do exercício, funciona também se o valor se repetir mais de duas vezes
        mas não passou no teste com um vetor vazio, passou 60/61
        
        int cont = 0;
        if (numsSize == 1)
        return nums[0];

        if (numsSize == 0)
        return ;

        for( int i = 0; i < numsSize ; i++){
            cont = 0;
            for( int j = 0; j < numsSize ; j++){
                if( nums[i]==nums[j] && i != j ){
                    cont++;
                }
            }
            if(cont == 0)
            return nums[i];
        }
        
    return nums[ numsSize-1 ];
    */
}