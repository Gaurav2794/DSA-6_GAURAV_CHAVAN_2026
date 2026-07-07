#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    if (top == -1)
        return '\0';
    return stack[top--];
}

int match(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isBalanced(char exp[]) {
    int i;
    char ch, open;

    for (i = 0; exp[i] != '\0'; i++) {
        ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1)
                return 0;

            open = pop();

            if (!match(open, ch))
                return 0;
        }
    }

    return (top == -1);
}

int main() {
    char exp[100];

    printf("Enter expression: ");
    scanf("%s", exp);

    if (isBalanced(exp))
        printf("Balanced Symbols\n");
    else
        printf("Not Balanced Symbols\n");

    return 0;
}