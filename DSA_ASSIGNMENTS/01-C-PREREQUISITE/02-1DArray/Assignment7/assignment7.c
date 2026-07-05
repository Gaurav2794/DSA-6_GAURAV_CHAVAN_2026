// Accept n elements in an array and search a perticular element

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, key;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("Element Found at index %d\n", i);
            break;
        }
    }

    if (i == n)
    {
        printf("Element Not Found\n");
    }

    free(arr);

    return 0;
}