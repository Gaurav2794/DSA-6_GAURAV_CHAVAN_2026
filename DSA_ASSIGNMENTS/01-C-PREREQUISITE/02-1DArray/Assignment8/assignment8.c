// - Accept n elements in an array and perform right rotaion and left rotation (rotate N elements (N is an user input))
// - NOTE: ALLOCATE ARRAY DYNAMICALLY

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, choice, temp;

    printf("Enter size of array: ");
    scanf("%d", &n);

    // Dynamic Memory Allocation
    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory Allocation Failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Number of rotations
    printf("Enter number of rotations: ");
    scanf("%d", &k);

    k = k % n;

    printf("\n1. Right Rotation");
    printf("\n2. Left Rotation");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        // Right Rotation
        for (j = 0; j < k; j++)
        {
            temp = arr[n - 1];

            for (i = n - 1; i > 0; i--)
            {
                arr[i] = arr[i - 1];
            }

            arr[0] = temp;
        }

        printf("\nArray after Right Rotation:\n");
    }
    else if (choice == 2)
    {
        // Left Rotation
        for (j = 0; j < k; j++)
        {
            temp = arr[0];

            for (i = 0; i < n - 1; i++)
            {
                arr[i] = arr[i + 1];
            }

            arr[n - 1] = temp;
        }

        printf("\nArray after Left Rotation:\n");
    }
    else
    {
        printf("Invalid Choice!\n");
        free(arr);
        return 0;
    }

    printf("\nFinal Array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}