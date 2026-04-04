#include <stdio.h>
int main(){
    char str[]= "Gaurav here";
    char *p = str;
    while(*p != '\0'){
        printf("%c", *p);
        p++;

    }
    return 0;
}