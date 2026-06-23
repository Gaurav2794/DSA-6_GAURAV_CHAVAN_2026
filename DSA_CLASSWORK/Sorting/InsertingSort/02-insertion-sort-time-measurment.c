#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void input(int* p_array, int N);
void output(int* p_array, int N, const char* msg);
void sort(int* p_array, int N);

int main(void)
{
    int* a = NULL;
    int N = 0;

    time_t t_start;
    time_t t_end;
    time_t t_delta;

    printf("Enter size of array:");
    scanf("%d", &N);

    if(N <= 0)
    {
        puts("Bad size for array");
        exit(EXIT_FAILURE);
    }

    a = (int*)malloc(N * sizeof(int));
    if(NULL == a)
    {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }

    input(a, N);
    t_start = time(0);
    sort(a, N);
    t_end = time(0);
    t_delta = t_end - t_start;
    printf("INTEGRAL TIME FOR SORT:%llu\n", t_delta);
    free(a);
    a = NULL;

    exit(EXIT_SUCCESS);
}


void input(int* p_array, int N)
{
    int cap = N * 10;
    int i;

    srand(time(0));

    i = 0;
    while(i < N)
    {
        p_array[i] = rand() % cap;
        i = i + 1;
    }
}

void output(int* p_array, int N, const char* msg)
{
    int i;

    if(NULL != msg)
        puts(msg);

    i = 0;
    while(i < N)
    {
        printf("a[%d]:%d\n", i, p_array[i]);
        i = i + 1;
    }
}

void sort(int* p_array, int N)
{
    int i, j;
    int key;

    j = 1;
    while(j < N)
    {
        key = p_array[j];

        i = j - 1;
        while(i > -1 && p_array[i] > key)
        {
            p_array[i+1] = p_array[i];
            i = i - 1;
        }

        p_array[i+1] = key;

        j = j + 1;
    }
}
