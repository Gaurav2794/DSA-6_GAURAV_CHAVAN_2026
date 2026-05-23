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

Node* insertPosition(Node* head, int value, int pos) {
    Node* newNode = createNode(value);

    if (pos == 1) {
        if (head == NULL) {
            newNode->next = newNode;
            return newNode;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;

        return newNode;
    }

    Node* temp = head;
    int i;

    for (i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;

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
    int n, i, value, pos, newValue;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("Original List:\n");
    display(head);

    printf("Enter position: ");
    scanf("%d", &pos);

    printf("Enter value to insert: ");
    scanf("%d", &newValue);

    head = insertPosition(head, newValue, pos);

    printf("Updated List:\n");
    display(head);

    head = destroyList(head);

    return 0;
}