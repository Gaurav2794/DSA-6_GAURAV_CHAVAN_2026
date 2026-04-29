/*
write a c program to Create a Singly linked list and Insert a node in the given position.
*/

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

node* insertAtTail(node* head, int value) {
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

node* insertAtPosition(node* head, int value, int pos) {
    node* newnode = createNode(value);
    if (newnode == NULL) return head;

    if (pos == 1) {
        newnode->next = head;
        return newnode;
    }

    node* temp = head;

    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position\n");
            free(newnode);
            return head;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        free(newnode);
        return head;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    return head;
}

void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
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
    int n, value, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        head = insertAtTail(head, value);
    }

    printf("\nOriginal List:\n");
    display(head);

    printf("\nEnter value to insert: ");
    scanf("%d", &value);

    printf("Enter position: ");
    scanf("%d", &pos);

    head = insertAtPosition(head, value, pos);

    printf("\nUpdated List:\n");
    display(head);

    destroy(head);

    return 0;
}