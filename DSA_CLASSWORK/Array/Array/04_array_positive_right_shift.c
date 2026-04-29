#include<stdio.h>
int main()
{
    int arr[8] = {-15, -8, -2, 1, 5, 15, 30, 45};
    int i=0;
    int temp = arr[7];
    for(i=6;i>=0;i--){
        if(arr[i] % 2 == 0){
            arr[i+1] = arr[i];
        }
        else{
            break;
        }
    }
    arr[3] = temp;
    printf("Array +ve Elements right shifted:\n");
    for(i=0;i<8;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}