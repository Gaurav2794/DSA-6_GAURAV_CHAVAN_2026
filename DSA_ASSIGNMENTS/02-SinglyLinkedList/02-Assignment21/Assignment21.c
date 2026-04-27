#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int id;
    char name[20];
    int value;
    struct node* next;
} node;

node* insert(node* head, int id, char name[], int value) {
    node* newnode = malloc(sizeof(node));

    newnode->id = id;
    strcpy(newnode->name, name);
    newnode->value = value;
    newnode->next = NULL;

    if (head == NULL)
        return newnode;

    node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newnode;
    return head;
}

node* insertAfterKey(node* head, int key, int id, char name[], int value) {
    node* temp = head;

    while (temp && temp->id != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Key not found\n");
        return head;
    }

    node* newnode = malloc(sizeof(node));
    newnode->id = id;
    strcpy(newnode->name, name);
    newnode->value = value;

    newnode->next = temp->next;
    temp->next = newnode;

    return head;
}

void display(node* head) {
    while (head) {
        printf("|_%d_|_%s_|_%d_| --> ", head->id, head->name, head->value);
        head = head->next;
    }
    printf("NULL\n");
}

void destroyList(node* head) {
    node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    node* head = NULL;
    int n, id, value, key;
    char name[20];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter id name value:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %s %d", &id, name, &value);
        head = insert(head, id, name, value);
    }

    printf("Original List:\n");
    display(head);

    printf("Enter key: ");
    scanf("%d", &key);

    printf("Enter new id name value:\n");
    scanf("%d %s %d", &id, name, &value);

    head = insertAfterKey(head, key, id, name, value);

    printf("Updated List:\n");
    display(head);

    destroyList(head);
    return 0;
}