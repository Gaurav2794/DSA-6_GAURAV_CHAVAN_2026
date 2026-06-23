#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

// Create Node
Node* createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

// Insert at Beginning
void insertBeginning(int value) {
    Node *newNode = createNode(value);

    if (newNode == NULL)
        return;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node *temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    printf("Inserted at beginning.\n");
}

// Insert at End
void insertEnd(int value) {
    Node *newNode = createNode(value);

    if (newNode == NULL)
        return;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        printf("Inserted at end.\n");
        return;
    }

    Node *temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;

    printf("Inserted at end.\n");
}

// Insert at Position
void insertPosition(int value, int pos) {
    if (pos == 1) {
        insertBeginning(value);
        return;
    }

    Node *newNode = createNode(value);

    if (newNode == NULL)
        return;

    Node *temp = head;
    int i;

    for (i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted at position %d.\n", pos);
}

// Delete from Beginning
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        printf("Deleted only node.\n");
        return;
    }

    Node *temp = head;
    Node *last = head;

    while (last->next != head) {
        last = last->next;
    }

    head = head->next;
    last->next = head;

    free(temp);

    printf("Deleted from beginning.\n");
}

// Delete from End
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        printf("Deleted only node.\n");
        return;
    }

    Node *temp = head;
    Node *prev = NULL;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);

    printf("Deleted from end.\n");
}

// Delete from Position
void deletePosition(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (pos == 1) {
        deleteBeginning();
        return;
    }

    Node *temp = head;
    Node *prev = NULL;
    int i;

    for (i = 1; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL || temp == head) {
        printf("Invalid position!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Deleted from position %d.\n", pos);
}

// Search
void search(int value) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node *temp = head;
    int pos = 1;

    do {
        if (temp->data == value) {
            printf("Element found at position %d\n", pos);
            return;
        }

        temp = temp->next;
        pos++;

    } while (temp != head);

    printf("Element not found!\n");
}

// Display
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node *temp = head;

    printf("CLL: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("[head]\n");
}

// Main Function
int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insertPosition(value, pos);
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePosition(pos);
                break;

            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;

            case 8:
                display();
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}