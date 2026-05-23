#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
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

Node* deleteByKey(Node* head, int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    Node* temp = head;

    do {
        if (temp->data == key) {
            if (temp->next == temp) {
                free(temp);
                return NULL;
            }

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            if (temp == head)
                head = temp->next;

            free(temp);
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
        printf("%d <-> ", temp->data);
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
    int n, i, value, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("Original List:\n");
    display(head);

    printf("Enter key to delete: ");
    scanf("%d", &key);

    head = deleteByKey(head, key);

    printf("Updated List:\n");
    display(head);

    head = destroyList(head);

    return 0;
}