#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int id;
    char name[20];
    struct node *prev;
    struct node *next;
} Node;

Node* createNode(int id, char name[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

Node* insertEnd(Node* head, int id, char name[]) {
    Node* newNode = createNode(id, name);

    if (head == NULL)
        return newNode;

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

Node* swapBlocks(Node* head) {
    if (head == NULL || head->next == NULL || 
        head->next->next == NULL || head->next->next->next == NULL) {
        return head;
    }

    Node *first = head;               // 1
    Node *second = head->next;        // 2
    Node *third = second->next;       // 3
    Node *fourth = third->next;       // 4
    Node *fifth = fourth->next;       // 5

    third->prev = NULL;
    fourth->next = first;

    first->prev = fourth;
    first->next = second;

    second->prev = first;
    second->next = fifth;

    if (fifth != NULL)
        fifth->prev = second;

    third->next = fourth;
    fourth->prev = third;

    head = third;

    return head;
}

void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        printf("|_%d_|_%s_| <--> ", temp->id, temp->name);
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

    head = insertEnd(head, 1, "AA");
    head = insertEnd(head, 2, "BB");
    head = insertEnd(head, 3, "CC");
    head = insertEnd(head, 4, "DD");
    head = insertEnd(head, 5, "EE");

    printf("Original List:\n");
    display(head);

    head = swapBlocks(head);

    printf("\nAfter Pointer Swap:\n");
    display(head);

    head = destroyList(head);

    return 0;
}