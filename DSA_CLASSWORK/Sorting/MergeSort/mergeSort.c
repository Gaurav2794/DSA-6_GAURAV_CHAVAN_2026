#include <stdio.h>
#include <stdlib.h>

void mergesort(int arr[], int temparr[], int low, int high);
void merge(int arr[], int temparr[], int low, int mid, int high);
void display(int arr[], int n, const char *msg);

int main()
{
    int arr[] = {48, 37, 43, 3, 4, 78, 10, 5};
    int n;
    int *temparr;

    n = sizeof(arr) / sizeof(arr[0]);

    temparr = (int *)malloc(n * sizeof(int));

    if (temparr == NULL)
    {
        printf("Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    display(arr, n, "Before Merge Sort:");

    mergesort(arr, temparr, 0, n - 1);

    display(arr, n, "After Merge Sort:");

    free(temparr);
    temparr = NULL;

    return 0;
}

void mergesort(int arr[], int temparr[], int low, int high)
{
    int mid;

    if (low >= high)
        return;

    mid = low + (high - low) / 2;

    mergesort(arr, temparr, low, mid);
    mergesort(arr, temparr, mid + 1, high);

    merge(arr, temparr, low, mid, high);
}

void merge(int arr[], int temparr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temparr[k++] = arr[i++];
        }
        else
        {
            temparr[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temparr[k++] = arr[i++];
    }

    while (j <= high)
    {
        temparr[k++] = arr[j++];
    }

    for (i = low; i <= high; i++)
    {
        arr[i] = temparr[i];
    }
}

void display(int arr[], int n, const char *msg)
{
    int i;

    if (msg != NULL)
        printf("%s\n", msg);

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}