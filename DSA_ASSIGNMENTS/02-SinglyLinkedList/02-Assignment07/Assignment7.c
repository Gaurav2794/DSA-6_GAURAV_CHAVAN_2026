/*
write a c program to Create a Singly linked list and Insert a node at Head
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* insertAtHead(node* head, int value) {
    node* newnode = (node*)malloc(sizeof(node));

    
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newnode->data = value;
    newnode->next = head;

    return newnode;
}


void display(node* head) {
    node* temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void destroyList(node* head) {
    node* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    printf("Memory freed successfully.\n");
}

int main() {
    node* head = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);

        head = insertAtHead(head, value);
    }

    printf("\nLinked List:\n");
    display(head);

    
    destroyList(head);

    return 0;
}