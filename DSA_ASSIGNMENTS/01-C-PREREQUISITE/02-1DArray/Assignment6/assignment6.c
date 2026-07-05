//Accept n elements in an array and revert the array
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    for(i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int start = 0, end = n - 1, temp;

    while(start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }

    printf("Reversed array:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}