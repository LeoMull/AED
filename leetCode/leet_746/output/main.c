#include <stdio.h>

int minCostClimbingStairs(int* cost, int costSize);
int main(int argc, char const *argv[])
{
    int m1[] = {10,15,20}, m1S = 3, m1C = 15, m2[] = {1,100,1,1,1,100,1,1,100,1}, m2S = 10, m2C = 6; 
    if(minCostClimbingStairs(m1, m1S) == m1C)
    printf("Valor certo\n");
    if(minCostClimbingStairs(m2, m2S) == m2C)
    printf("Valor certo\n");
    return 0;
}

int minCostClimbingStairs(int* cost, int costSize){
    for(int i =2; i<costSize;i++){
        cost[i]+= (cost[i-1] < cost[i-2]) ? cost[i-1]: cost[i-2];
    } 
    return (cost[costSize-1] < cost[costSize-2]) ? cost[costSize-1]: cost[costSize-2];
}
