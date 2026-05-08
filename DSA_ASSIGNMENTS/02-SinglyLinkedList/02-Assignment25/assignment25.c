#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int id;
    char name[20];
    struct node *next;
} Node;

Node* createNode(int id, char name[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->next = NULL;

    return newNode;
}

Node* insertEnd(Node* head, int id, char name[]) {
    Node* newNode = createNode(id, name);

    if (head == NULL)
        return newNode;

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}

int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        printf("|_%d_|_%s_| --> ", temp->id, temp->name);
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
    int size;

    head = insertEnd(head, 1, "AA");
    head = insertEnd(head, 2, "BB");
    head = insertEnd(head, 3, "CC");
    head = insertEnd(head, 4, "DD");

    printf("Linked List:\n");
    display(head);

    size = countNodes(head);

    printf("\nSize of list = %d\n", size);

    head = destroyList(head);

    return 0;
}