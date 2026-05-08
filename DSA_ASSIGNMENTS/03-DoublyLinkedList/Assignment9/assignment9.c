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

Node* insertEnd(Node* head, int value) {
    Node* newNode = createNode(value);

    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

Node* deleteByKey(Node* head, int key) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    Node* temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key not found!\n");
        return head;
    }

    if (temp == head) {
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        }

        free(temp);
        return head;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    temp->prev->next = temp->next;

    free(temp);

    return head;
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
    Node* head = NULL;
    int n, value, key, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Enter value for node %d: ", i);
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("\nOriginal List:\n");
    display(head);

    printf("\nEnter key to delete: ");
    scanf("%d", &key);

    head = deleteByKey(head, key);

    printf("\nUpdated List:\n");
    display(head);

    head = destroyList(head);

    return 0;
}