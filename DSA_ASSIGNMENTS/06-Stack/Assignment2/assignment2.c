#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} stk;

stk* push(stk* top, int data) {
    stk* newnode = (stk*)malloc(sizeof(stk));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return top;
    }
    newnode->data = data;
    newnode->next = top;
    top = newnode;
    return top;
}

stk* pop(stk* top) {
    if (top == NULL) {
        printf("Stack underflow\n");
        return top;
    }

    stk* temp = top;
    printf("%d popped\n", top->data);
    top = top->next;
    free(temp);
    return top;
}

void peek(stk* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", top->data);
}

void display(stk* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    stk* temp = top;
    printf("\nTop -> ");
    while (temp != NULL) {
        printf("[%d] -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    stk* top = NULL;

    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = push(top, 40);

    display(top);

    top = pop(top);
    top = pop(top);

    peek(top);
    display(top);

    printf("End of program\n");

    return 0;
}