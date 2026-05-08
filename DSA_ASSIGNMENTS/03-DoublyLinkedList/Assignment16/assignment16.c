#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

Node* insertEnd(Node* head, int value) {
    Node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

void rearrangePairs(Node* head) {
    Node* temp = head;

    while (temp != NULL && temp->next != NULL) {

        if (temp->data > temp->next->data) {
            int swap = temp->data;
            temp->data = temp->next->data;
            temp->next->data = swap;
        }

        temp = temp->next->next;
    }
}

void display(Node* head) {
    Node* temp = head;

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
    Node* head = NULL;
    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Enter value %d: ", i);
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("\nOriginal List:\n");
    display(head);

    rearrangePairs(head);

    printf("\nRearranged List:\n");
    display(head);

    head = destroyList(head);

    return 0;
}