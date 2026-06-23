#include <stdio.h>

#define MAX     5
#define SUCCESS 1
#define FAILURE 0

typedef struct stack {
    int arr[MAX];
    int top;
} stack_t;

void init_stack(stack_t *s) {
    s->top = -1;
}

int is_full(stack_t *s) {
    return s->top == MAX - 1;
}

int is_empty(stack_t *s) {
    return s->top == -1;
}

int push(stack_t *s, int data) {
    if (is_full(s))
        return FAILURE;

    s->arr[++s->top] = data;
    return SUCCESS;
}

int pop(stack_t *s, int *delete_data) {
    if (is_empty(s))
        return FAILURE;

    *delete_data = s->arr[s->top--];
    return SUCCESS;
}

int peek(stack_t *s, int *top_data) {
    if (is_empty(s))
        return FAILURE;

    *top_data = s->arr[s->top];
    return SUCCESS;
}

void display(stack_t *s) {
    if (is_empty(s)) {
        printf("Stack is Empty\n");
        return;
    }

    printf("\nTOP -> ");
    for (int i = s->top; i >= 0; i--) {
        printf("[%d] ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    stack_t s;
    int data;

    init_stack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    display(&s);

    if (peek(&s, &data) == SUCCESS)
        printf("\nTOP Element: %d\n", data);

    if (pop(&s, &data) == SUCCESS)
        printf("\nDeleted Element: %d\n", data);

    display(&s);

    return 0;
}