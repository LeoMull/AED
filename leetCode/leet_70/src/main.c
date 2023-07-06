#include <stdio.h>

int ClimbStairs(int n);

int main(int argc, char const *argv[])
{
    printf("Total: %d\n", ClimbStairs(2));
    printf("Total: %d\n", ClimbStairs(3));
    printf("Total: %d\n", ClimbStairs(4));
    printf("Total: %d\n", ClimbStairs(5));

    return 0;
}

int ClimbStairs(int n){
    int total[n];

    total[0]=1;
    
    if ( n>1 )
    total[1] = 2;

    for( int i = 2 ; i<n ; i++ ){
        total[i] = total[i-1] + total[i-2];
    }
    return total[n-1];
}