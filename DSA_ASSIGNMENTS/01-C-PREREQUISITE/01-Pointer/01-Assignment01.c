#include <stdio.h>

int main(){
    int a[3]={1,2,3};
    int b[3]={4,5,6};

    int *p = a;
    int *q = b;
    int temp;

    for(int i=0;i<3;i++){
        temp = *(p+i);
        *(p+i)= *(q+i);
        *(q+i)= temp;
    }
    printf("First Array: ");
    for(int i =0;i<3;i++){
        printf("%d ", a[i]);
    }
    printf("\nSecond Array: ");
    for(int i =0;i<3;i++){
        printf("%d ", b[i]);
    }
    return 0;
}