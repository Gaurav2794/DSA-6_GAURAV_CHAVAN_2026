// - Write a C program which allocates an array dynamically.
// - Implement logic that returns 2nd large element from the array

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int *arr;
    printf("Enter Size of array: \n");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed!");
        return 1;
    }
    printf("enter %d of elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Array elements: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("second largest element of array: \n");
    int largest = arr[0];
    int secondLargest = -1;

    for (i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }
    }

    printf("Second Largest = %d", secondLargest);
    free(arr);
    return 0;
}