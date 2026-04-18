/*
- write a C program to create memory for 
int, char and float variable at 
run time. - create memory for int, char 
and float variables at run time using malloc() function 
- and before exiting the program release the memory allocated 
at run time by using free() function. from now give me standard codes only
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *i;
    char *c;
    float *f;

    i = (int*)malloc(sizeof(int));
    c = (char*)malloc(sizeof(char));
    f = (float*)malloc(sizeof(float));
    if (i == NULL || c == NULL || f == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    *i = 10;
    *c = 'A';
    *f = 5.5;

    printf("Integer value: %d\n", *i);
    printf("Character value: %c\n", *c);
    printf("Float value: %.2f\n", *f);

    free(i);
    free(c);
    free(f);

    return 0;
}
