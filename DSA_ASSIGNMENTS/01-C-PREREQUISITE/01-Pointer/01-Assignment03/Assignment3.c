/*
write a Program to print a string using pointer.
*/

#include <stdio.h>

int main(){
    int arr[100] , n;
    int *ptr;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    ptr = arr;

    printf("Enter elements: \n");
    for(int i = 0 ; i<n;i++){
        scanf("%d", (ptr+i));
    }

    printf("\nElements with their addresses:\n");
    for(int i=0; i<n;i++ ){
        printf("Value = %d, Address = %p\n", *(ptr + i), (void*)(ptr + i));
    }
    return 0;
}