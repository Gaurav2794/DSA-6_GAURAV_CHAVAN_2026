/*
write a  Program to count vowels and consonants in a string using pointer.

*/

#include <stdio.h>

int main(){
    char str[100];
    char *ptr;
    int vowels = 0 , consonants = 0;

    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    ptr = str;
    while(*ptr != '\0'){
        if (*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u' ||
            *ptr == 'A' || *ptr == 'E' || *ptr == 'I' || *ptr == 'O' || *ptr == 'U') {
            vowels++;
        } else {
            consonants++;
        }
        ptr++;
    }

    printf("Vowels= %d\n",vowels);
    printf("Consonents = %d\n", consonants);

    return 0;
}