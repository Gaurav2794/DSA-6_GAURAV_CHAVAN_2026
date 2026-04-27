#include <stdio.h>

void reverseString(char str[]) {
    int i = 0, j = 0;
    char temp;

    while (str[j] != '\0') {
        j++;
    }
    j--;  

    if (str[j] == '\n') {
        str[j] = '\0';
        j--;
    }

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        i++;
        j--;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}