// Write a C program which accepts an array dynamically
// Find the subarray with maximum sum

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    // Dynamic memory allocation
    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter elements of array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nArray: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    int maxsum = arr[0];
    int currsum = arr[0];
    int start = 0, end = 0, temp = 0;

    for (i = 1; i < n; i++)
    {
        if (currsum + arr[i] < arr[i])
        {
            currsum = arr[i];
            temp = i;
        }
        else
        {
            currsum += arr[i];
        }

        if (currsum > maxsum)
        {
            maxsum = currsum;
            start = temp;
            end = i;
        }
    }

    printf("\n\nMaximum Sum = %d\n", maxsum);

    printf("Maximum Subarray: ");
    for (i = start; i <= end; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    free(arr);

    return 0;
}