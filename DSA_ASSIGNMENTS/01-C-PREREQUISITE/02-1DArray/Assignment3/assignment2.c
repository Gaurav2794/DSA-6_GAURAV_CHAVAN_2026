

// - Write a C program which allocates an array dynamically.
// - Implement logic that removes duplicate elements from the array.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    printf("Enter size of Array: \n");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Array elements are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                for (int k = j; k < n - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                n--;
                j--;
            }
        }
    }
    printf("\nArray after removing duplicates:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Free the allocated memory
    free(arr);
    return 0;
}