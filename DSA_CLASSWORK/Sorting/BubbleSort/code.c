#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n){
    int temp;
    for(int i=0 ; i<= n-1; i++){
        for(int j = 0 ; j <n-i-1 ; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]= temp;
            }
        }
    }
}
void display(int arr[],int n){
    printf("Sorted Array : \n");
    for(int i =0 ;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main(void){
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter %d elements: ",n);
    for(int i=0; i<n ;i++){
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr ,n);
    display(arr,n);

}