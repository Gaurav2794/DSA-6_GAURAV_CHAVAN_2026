/*
write a c program to Create a Singly linked list and Delete the node in the given position
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* insert(node* head, int value) {
    node* newnode = malloc(sizeof(node));
    if (newnode == NULL) return head;

    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL)
        return newnode;

    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    return head;
}

node* deleteAtPosition(node* head, int pos) {
    if (head == NULL || pos <= 0)
        return head;

    if (pos == 1) {
        node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    node* temp = head;

    // move to (pos-1) node safely
    for (int i = 1; i < pos - 1; i++) {
        if (temp->next == NULL)
            return head;
        temp = temp->next;
    }

    if (temp->next == NULL)
        return head;

    node* del = temp->next;
    temp->next = del->next;
    free(del);

    return head;
}

void display(node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    node* head = NULL;
    int n, value, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insert(head, value);
    }

    printf("List: ");
    display(head);

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    head = deleteAtPosition(head, pos);

    printf("Updated List: ");
    display(head);

    return 0;
}