/*Write a function to calculate the sum of all elements of an array*/
#include <stdio.h>

int sumArray(int arr[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Sum = %d", sumArray(arr, size));
    return 0;
}