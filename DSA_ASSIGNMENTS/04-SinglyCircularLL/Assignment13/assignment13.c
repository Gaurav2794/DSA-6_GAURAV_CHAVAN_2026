#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int roll;
    char name[20];
    int marks;
    struct node* next;
} Node;

Node* createNode(int roll, char name[], int marks) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->marks = marks;
    newNode->next = NULL;
    return newNode;
}

Node* insertEnd(Node* head, int roll, char name[], int marks) {
    Node* newNode = createNode(roll, name, marks);

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

Node* deleteBeforeKey(Node* head, int key) {
    if (head == NULL || head->next == head) {
        printf("Not enough nodes\n");
        return head;
    }

    Node *prev, *curr, *temp;

    if (head->next->roll == key) {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        head = head->next;
        temp->next = head;
        free(temp);

        return head;
    }

    prev = head;
    curr = head->next;

    while (curr->next != head && curr->next->roll != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr->next == head) {
        printf("Key not found\n");
        return head;
    }

    prev->next = curr->next;
    free(curr);

    return head;
}

void display(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;

    do {
        printf("|_%d_|_%s_|_%d_| --> ", temp->roll, temp->name, temp->marks);
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
    int n, i, roll, marks, key;
    char name[20];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter roll, name, marks: ");
        scanf("%d %s %d", &roll, name, &marks);
        head = insertEnd(head, roll, name, marks);
    }

    printf("Original List:\n");
    display(head);

    printf("Enter key: ");
    scanf("%d", &key);

    head = deleteBeforeKey(head, key);

    printf("Updated List:\n");
    display(head);

    head = destroyList(head);

    return 0;
}