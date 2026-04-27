/*write a function to find the length of a string.*/
#include <stdio.h>

int stringLength(char str[]) {
    int i = 0;
    while(str[i] != '\0') {
        i++;
    }
    return i;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Length = %d", stringLength(str) - 1); // remove newline

    return 0;
}