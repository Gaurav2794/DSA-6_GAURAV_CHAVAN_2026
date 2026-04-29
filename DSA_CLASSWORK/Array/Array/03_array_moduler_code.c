#include<stdio.h>

void display(int arr[], int size){
    printf("Array Elements:\n");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
}
void rightShift(int arr[], int size){
    int temp = arr[size-1];
    for(int i=size-2; i>=0; i--){
        arr[i+1] = arr[i];
    }
    arr[0] = temp;
}
int initializeArray(int arr[], int size){
    for(int i=0; i<size; i++){
        arr[i] = (i+1)*10;
    }
}

int main(){
    int arr[8];
    initializeArray(arr,8);
    display(arr,8);
    rightShift(arr,8);
    display(arr,8);
    return 0;
}
