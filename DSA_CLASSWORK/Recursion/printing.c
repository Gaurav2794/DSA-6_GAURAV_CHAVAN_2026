#include <stdio.h>
#include <stdlib.h>
//printing o. from 1 to 5 and reverse

void counter(int n)
{
    printf("%d \n",n);
    if(n<=5)
        counter(n+1);
    printf("%d \n",n);
}

int main(void)
{
    int n=1;
    counter(n);
    return 0;
}