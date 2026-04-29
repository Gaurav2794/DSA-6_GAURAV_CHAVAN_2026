#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* createNode(int value) {
    node* newnode = (node*)malloc(sizeof(node));
    if (newnode == NULL) return NULL;

    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

node* insertAtLast(node* head, int value) {
    node* newnode = createNode(value);
    if (newnode == NULL) return head;

    if (head == NULL)
        return newnode;

    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    return head;
}

void display(node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void destroy(node* head) {
    node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    node* head = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1) return 0;

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertAtLast(head, value);
    }

    printf("Enter value to insert at last: ");
    scanf("%d", &value);

    head = insertAtLast(head, value);

    printf("Updated List:\n");
    display(head);

    destroy(head);
    return 0;
}