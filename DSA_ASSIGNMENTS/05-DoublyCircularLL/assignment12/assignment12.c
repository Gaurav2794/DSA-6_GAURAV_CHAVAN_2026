#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int roll;
    char name[20];
    struct node* prev;
    struct node* next;
} Node;

Node* createNode(int roll, char name[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node* insertEnd(Node* head, int roll, char name[]) {
    Node* newNode = createNode(roll, name);

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }

    Node* last = head->prev;

    last->next = newNode;
    newNode->prev = last;
    newNode->next = head;
    head->prev = newNode;

    return head;
}

Node* insertBeforeKey(Node* head, int key, int roll, char name[]) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    Node* temp = head;

    do {
        if (temp->roll == key) {
            Node* newNode = createNode(roll, name);

            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            temp->prev = newNode;

            if (temp == head)
                head = newNode;

            return head;
        }

        temp = temp->next;

    } while (temp != head);

    printf("Key not found\n");
    return head;
}

void display(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;

    do {
        printf("|_%d_|_%s_| <--> ", temp->roll, temp->name);
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
    int n, i, roll, key;
    char name[20];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter roll and name: ");
        scanf("%d %s", &roll, name);
        head = insertEnd(head, roll, name);
    }

    printf("Original List:\n");
    display(head);

    printf("Enter key: ");
    scanf("%d", &key);

    printf("Enter new roll and name: ");
    scanf("%d %s", &roll, name);

    head = insertBeforeKey(head, key, roll, name);

    printf("Updated List:\n");
    display(head);

    head = destroyList(head);

    return 0;
}