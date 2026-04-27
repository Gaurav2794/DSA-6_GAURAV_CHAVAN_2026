/*
write a c program to Create a Singly linked list
and Find and print the middle element
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
void findMiddle(node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node* slow = head;
    node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Middle element: %d\n", slow->data);
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
    int n, value;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insert(head, value);
    }
    printf("List: ");
    display(head);
    findMiddle(head);
    destroyList(head);
    return 0;
}