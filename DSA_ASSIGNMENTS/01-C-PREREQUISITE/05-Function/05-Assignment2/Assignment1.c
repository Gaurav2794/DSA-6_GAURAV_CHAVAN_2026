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
    char str[] = "Hello";
    printf("Length = %d", stringLength(str));
    return 0;
}