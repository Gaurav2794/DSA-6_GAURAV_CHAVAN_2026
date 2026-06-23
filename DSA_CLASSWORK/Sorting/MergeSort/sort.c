#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high){
    int i = low;
    int j = mid + 1;
    int k = 0; // Start at 0 for the temp array
    int temp[high - low + 1];

    while(i <= mid && j <= high){
        if(arr[i] < arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }

    while(i <= mid){
        temp[k++] = arr[i++];
    }

    while(j <= high){
        temp[k++] = arr[j++];
    }

    // Correctly copy back elements 
    for(i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
}

void mergeSort(int arr[], int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main(){
    int arr[] = {48, 37, 43, 3, 4, 78, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int low = 0;
    int high = n - 1;

    mergeSort(arr, low, high);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    
    return 0; // Good practice to end main
}
