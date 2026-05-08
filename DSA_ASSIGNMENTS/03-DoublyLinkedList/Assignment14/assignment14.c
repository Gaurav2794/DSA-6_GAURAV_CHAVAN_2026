#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

Node* insertSorted(Node* head, int value) {
    Node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    if (value < head->data) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->data < value)
        temp = temp->next;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    return head;
}

Node* mergeLists(Node* head1, Node* head2) {
    Node* merged = NULL;
    Node* temp;

    temp = head1;
    while (temp != NULL) {
        merged = insertSorted(merged, temp->data);
        temp = temp->next;
    }

    temp = head2;
    while (temp != NULL) {
        merged = insertSorted(merged, temp->data);
        temp = temp->next;
    }

    return merged;
}

void display(Node* head) {
    Node* temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

Node* destroyList(Node* head) {
    Node* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return NULL;
}

int main() {
    Node *head1 = NULL, *head2 = NULL, *merged = NULL;
    int n1, n2, value, i;

    printf("Enter number of nodes for List 1: ");
    scanf("%d", &n1);

    for (i = 1; i <= n1; i++) {
        printf("Enter value %d for List 1: ", i);
        scanf("%d", &value);
        head1 = insertSorted(head1, value);
    }

    printf("Enter number of nodes for List 2: ");
    scanf("%d", &n2);

    for (i = 1; i <= n2; i++) {
        printf("Enter value %d for List 2: ", i);
        scanf("%d", &value);
        head2 = insertSorted(head2, value);
    }

    printf("\nList 1:\n");
    display(head1);

    printf("\nList 2:\n");
    display(head2);

    merged = mergeLists(head1, head2);

    printf("\nMerged Sorted List:\n");
    display(merged);

    head1 = destroyList(head1);
    head2 = destroyList(head2);
    merged = destroyList(merged);

    return 0;
}