#include<stdio.h>

int main(){
    int arr[8] ;
    int i=0;
    while(i<8){
        arr[i] = (i+1)*10;
        i++;
    }
    printf("Array Elements:\n");
    for(i=0;i<8;i++){
        printf("%d ",arr[i]);
    }
        return 0;
}