 
 	
// - Write a C program which allocates two array dynamically.
// - Implement logic to merge and sort two array.

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *arr1, *arr2, *merge;
    int n1, n2, i, j, temp;

    // Input size of first array
    printf("Enter size of first array: ");
    scanf("%d", &n1);

    arr1 = (int *)malloc(n1 * sizeof(int));

    printf("Enter %d elements:\n", n1);
    for(i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    // Input size of second array
    printf("Enter size of second array: ");
    scanf("%d", &n2);

    arr2 = (int *)malloc(n2 * sizeof(int));

    printf("Enter %d elements:\n", n2);
    for(i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }
    //allocating merge array's memory
    merge = (int*)malloc((n1+n2)*sizeof(int));

    //copy first array
    for(i=0;i < n1;i++){
        merge[i]=arr1[i];
    }
    // Copy second array
    for(i = 0; i < n2; i++)
    {
        merge[n1 + i] = arr2[i];
    }

    //merge sort
    for(i=0;i < n1+n2-1;i++){
        for(j=0;j<n1+n2-i-1;j++){
            if(merge[j]>merge[j+1]){
                temp=merge[j];
                merge[j]=merge[j+1];
                merge[j+1]=temp;
            }
        }
    }
    printf("Merged and Sorted Array:\n");
    for(i = 0; i < n1 + n2; i++)
    {
        printf("%d ", merge[i]);
    }

    // Free allocated memory
    free(arr1);
    free(arr2);
    free(merge);

    return 0;



}