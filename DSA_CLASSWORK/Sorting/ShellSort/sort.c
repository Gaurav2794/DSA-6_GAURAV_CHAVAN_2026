#include <stdio.h>
#include <stdlib.h>

void shellSort(int a[],int low , int high);
void display(int a[],int N , const char *msg);


void shellSort(int a[],int low, int high){
    
    int gap = (high - low + 1) / 2;
    while (gap > 0)
    {
        for (int i = low + gap; i <= high; i++)
        {
            int temp = a[i];
            int j = i;
            while (j >= low + gap && a[j - gap] > temp)
            {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = temp;
        }
        gap = gap / 2;
    }
}

int main()
{
    int arr[] = {48, 37, 43, 3, 78, 10, 50};

    int n = sizeof(arr) / sizeof(arr[0]);

    display(arr, n, "Before Shell Sort:");

    shellSort(arr, 0, n - 1);

    display(arr, n, "After Shell Sort:");

    return 0;
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
