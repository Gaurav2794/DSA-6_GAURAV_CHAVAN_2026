/*
Write Program to print addresses and size of all types of pointer variables.
*/

#include <stdio.h>

int main() {
    int a;
    float b;
    char c;

    int *p1 = &a;
    float *p2 = &b;
    char *p3 = &c;

    printf("Address of int pointer: %p\n", p1);
    printf("Size of int pointer: %lu\n\n", sizeof(p1));

    printf("Address of float pointer: %p\n", p2);
    printf("Size of float pointer: %lu\n\n", sizeof(p2));

    printf("Address of char pointer: %p\n", p3);
    printf("Size of char pointer: %lu\n", sizeof(p3));

    return 0;
}