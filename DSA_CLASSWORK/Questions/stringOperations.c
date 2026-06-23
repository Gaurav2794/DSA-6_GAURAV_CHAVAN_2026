/*
19/06/2026
input : "7m8y 8i9s 1a3b4c 6n3a2m8e"
Output : "my name is abc"
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// int main(){
//     char s[]={"7m8y 8i9s 1a3b4c 6n3a2m8e"};
//     int i;
//     while(s[i] != '\0'){
//         if(!(s[i] >= '0' && s[i]<='9')){
//             printf("%c ",s[i]);
//         }
//         i++;

//     }
//     return 0;
// }


//Homework 
//ip: best of luck 
//op: luck of best
//op: kcul fo tseb
//op: palindrome

int main(void){
    char s[] = "7m8y 8i9s 1a3b4c 6n3a2m8e";
    int i=0;
    while(s[i] != '\0'){
        if(!isdigit(s[i])){
            printf("%c",s[i]);
        }
        i++;
    }
    return 0;
}