/*
write a c program to Create a Singly linked list and Delete 
the node depending on user input key/value
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* insert(node* head, int value) {
    node* newnode = (node*)malloc(sizeof(node));
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

node* deleteByValue(node* head, int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    if (head->data == key) {
        node* temp = head;
        head = head->next;
        free(temp);
        printf("Node with value %d deleted\n", key);
        return head;
    }

    node* temp = head;

    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Value %d not found in list\n", key);
        return head;
    }

    node* del = temp->next;
    temp->next = del->next;
    free(del);

    printf("Node with value %d deleted\n", key);
    return head;
}

void display(node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
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
}

int main() {
    node* head = NULL;
    int n, value, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insert(head, value);
    }

    printf("List: ");
    display(head);

    printf("Enter value to delete: ");
    scanf("%d", &key);

    head = deleteByValue(head, key);

    printf("Updated List: ");
    display(head);

    destroyList(head);

    return 0;
}