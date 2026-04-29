/*
Write a program to find sum of two arrays using pointers
*/

#include <stdio.h>

int main() {
    int a[100], b[100], sum[100];
    int n;
    int *p1, *p2, *p3;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements of first array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter elements of second array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    p1 = a;
    p2 = b;
    p3 = sum;

    for (int i = 0; i < n; i++) {
        *(p3 + i) = *(p1 + i) + *(p2 + i);
    }

    printf("Sum of arrays:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(p3 + i));
    }

    return 0;
}