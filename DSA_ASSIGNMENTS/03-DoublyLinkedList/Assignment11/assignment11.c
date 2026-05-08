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

Node* createList(Node* head) {
    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Enter value for node %d: ", i);
        scanf("%d", &value);

        Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    return head;
}

Node* insertNode(Node* head) {
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);

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

Node* deleteNode(Node* head) {
    int key;

    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    printf("Enter value to delete: ");
    scanf("%d", &key);

    Node* temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found!\n");
        return head;
    }

    if (temp == head) {
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        free(temp);
        return head;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

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

void reverseDisplay(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
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
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Create\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Reverse Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = destroyList(head);
                head = createList(head);
                break;

            case 2:
                head = insertNode(head);
                break;

            case 3:
                head = deleteNode(head);
                break;

            case 4:
                display(head);
                break;

            case 5:
                reverseDisplay(head);
                break;

            case 6:
                head = destroyList(head);
                printf("Program exited.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}