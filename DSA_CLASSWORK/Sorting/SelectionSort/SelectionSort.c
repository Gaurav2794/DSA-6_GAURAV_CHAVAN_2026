#include <stdio.h>
#include <stdlib.h>

int selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int low = i;
        for(int j=i+1;j<n;j++){
            arr[j]<arr[low];
            low = j;
        }
        int temp = arr[low];
        arr[low] = arr[i];
        arr[i] = temp;
    }
    printf("Sorted Array : \n");
    for(int i =0 ;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter %d elements: ",n);
    for(int i=0; i<n ;i++){
        scanf("%d", &arr[i]);
    }
    selectionSort(arr ,n);
}