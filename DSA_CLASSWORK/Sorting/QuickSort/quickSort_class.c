#include <stdio.h>
#include <stdlib.h>

void quickSort(int a[], int start, int end);
int partition(int a[], int start, int end);
void swap(int *p1, int *p2);
void display(int a[], int N, const char *msg);

int main()
{
    int a[] = {50, 6, 44, 68, 12, 1};
    int N;
    N = sizeof(a) / sizeof(a[0]);
    display(a, N, "Before quick sort: ");
    quickSort(a, 0, N - 1);
    display(a, N, "After quicksort: ");

    return (0);
}

void quickSort(int a[], int start, int end)
{
    int pivot_index;
    if (start >= end)
    {
        return;
    }
    pivot_index = partition(a, start, end);
    quickSort(a, start, pivot_index - 1);
    quickSort(a, pivot_index + 1, end);
}

int partition(int a[], int start, int end)
{
    int pivot;
    int i;
    int j;
    pivot = a[start];
    i = start + 1;
    j = end;
    while (i <= j)
    {
        while (i <= end && a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
            j--;
        if (i < j)
        {
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[start], &a[j]);
    return j;
}
void swap(int *p1, int *p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void display(int a[], int N, const char *msg)
{
    int i;
    if (msg != NULL)
    {
        puts(msg);
    }
    for (i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}