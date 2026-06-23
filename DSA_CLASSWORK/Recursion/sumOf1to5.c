#include <stdio.h>
#include <stdlib.h>

int add(int n){
    int sum =0;
    if(n==5)
        return n;
    
    return(n+add(n+1));
}

int main(void)
{
    int n=1;
    int sum = add(n);
    printf("sum = %d ",sum);
}