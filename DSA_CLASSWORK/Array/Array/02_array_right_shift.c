#include<stdio.h>
int main(){
    int arr[8];
    int i=0;
    for(i =0;i<8;i++){
        arr[i] = (i+1)*10;
    }
    int temp;
    temp = arr[7];
    for(i=6;i>=0;i--){
        arr[i+1] = arr[i];
    }
    arr[0] = temp;
    printf("Array Elements after Right shifting:\n");
    for(i=0;i<8;i++){
        printf("%d ",arr[i]);
    }
}