// - Write a C program which allocates an array dynamically.
// - Implement logic which accepts only unique elements in array
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int n, i, j, duplicate;

    printf("Enter size of array: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if(arr == NULL)
    {
        printf("Memory Allocation Failed!");
        return 1;
    }

    for(i = 0; i < n; )
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);

        duplicate = 0;

        for(j = 0; j < i; j++)
        {
            if(arr[i] == arr[j])
            {
                duplicate = 1;
                break;
            }
        }

        if(duplicate == 1)
        {
            printf("Duplicate element! Enter again.\n");
        }
        else
        {
            i++;   
        }
    }

    printf("\nUnique Array:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}