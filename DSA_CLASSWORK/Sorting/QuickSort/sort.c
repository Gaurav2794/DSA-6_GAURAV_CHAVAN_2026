#include <stdio.h>
#include <stdlib.h>

void quicksort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void display(int arr[], int n, const char *msg);

int main()
{
    int arr[] = {48, 37, 43, 3, 78, 10, 50};

    int n = sizeof(arr) / sizeof(arr[0]);

    display(arr, n, "Before Quick Sort:");

    quicksort(arr, 0, n - 1);

    display(arr, n, "After Quick Sort:");

    return 0;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quicksort(arr, low, pivot - 1);

        quicksort(arr, pivot + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;

    for(int j = low + 1; j <= high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[low];
    arr[low] = arr[i];
    arr[i] = temp;

    return i;
}

void display(int arr[], int n, const char *msg)
{
    printf("%s\n", msg);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}