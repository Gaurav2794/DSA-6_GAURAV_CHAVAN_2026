#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node* insertEnd(Node* head, int value) {
    Node* newNode = createNode(value);

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    Node* temp = head;

    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;

    return head;
}

Node* deleteEnd(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if (head->next == head) {
        free(head);
        return NULL;
    }

    Node* temp = head;

    while (temp->next->next != head)
        temp = temp->next;

    Node* del = temp->next;
    temp->next = head;

    free(del);

    return head;
}

void display(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("HEAD\n");
}

Node* destroyList(Node* head) {
    if (head == NULL)
        return NULL;

    Node* temp = head->next;
    Node* nextNode;

    while (temp != head) {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    free(head);

    return NULL;
}

int main() {
    Node* head = NULL;
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("Original List:\n");
    display(head);

    head = deleteEnd(head);

    printf("After deleting last node:\n");
    display(head);

    head = destroyList(head);

    return 0;
}