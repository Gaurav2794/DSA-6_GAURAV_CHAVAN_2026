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

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;

    return head;
}

Node* deleteAfterKey(Node* head, int key) {
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }

    Node* temp = head;

    while (temp != NULL && temp->id != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key not found!\n");
        return head;
    }

    if (temp->next == NULL) {
        printf("No node exists after key!\n");
        return head;
    }

    Node* deleteNode = temp->next;

    temp->next = deleteNode->next;

    free(deleteNode);

    return head;
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
    int key;

    head = insertEnd(head, 1, "AA");
    head = insertEnd(head, 2, "BB");
    head = insertEnd(head, 3, "CC");
    head = insertEnd(head, 4, "DD");

    printf("Original List:\n");
    display(head);

    printf("\nEnter key: ");
    scanf("%d", &key);

    head = deleteAfterKey(head, key);

    printf("\nUpdated List:\n");
    display(head);

    head = destroyList(head);

    return 0;
}