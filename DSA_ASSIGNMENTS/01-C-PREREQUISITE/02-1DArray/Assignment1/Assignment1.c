#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    int visited[n];

    for(i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nFrequency of elements:\n");

    for(i = 0; i < n; i++)
    {
        if(visited[i] == 1)
            continue;

        int count = 1;

        for(j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
                visited[j] = 1;
            }
        }

        printf("%d occurs %d times\n", arr[i], count);
    }

    free(arr);

    return 0;
}