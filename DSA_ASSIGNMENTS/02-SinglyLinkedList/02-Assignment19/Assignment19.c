/*
write a c program to Create a Singly linked 
list and perform menu driven which includes 
following functions: - create(), - Insert(), - Delete(), - Reverse(), - print()
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* create() {
    node* head = NULL;
    node* temp = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        node* newnode = (node*)malloc(sizeof(node));
        scanf("%d", &value);

        newnode->data = value;
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

node* insert(node* head, int value) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL)
        return newnode;

    node* temp = head;
    while (temp->next)
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
        return head;
    }

    node* temp = head;
    while (temp->next && temp->next->data != key)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Value not found\n");
        return head;
    }

    node* del = temp->next;
    temp->next = del->next;
    free(del);

    return head;
}

node* reverse(node* head) {
    node *prev = NULL, *curr = head, *next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void print(node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void destroyList(node* head) {
    node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    node* head = NULL;
    int choice, value;

    while (1) {
        printf("\n1.Create\n2.Insert\n3.Delete\n4.Reverse\n5.Print\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                destroyList(head);
                head = create();
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insert(head, value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                head = deleteByValue(head, value);
                break;

            case 4:
                head = reverse(head);
                printf("List reversed\n");
                break;

            case 5:
                print(head);
                break;

            case 6:
                destroyList(head);
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}