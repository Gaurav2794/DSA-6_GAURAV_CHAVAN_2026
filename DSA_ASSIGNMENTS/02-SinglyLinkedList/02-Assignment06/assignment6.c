#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int id;
    char name[20];
    int value;
    struct node* next;
} node;

node* createNode(int id, char name[], int value) {
    node* n = (node*)malloc(sizeof(node));
    n->id = id;
    strcpy(n->name, name);
    n->value = value;
    n->next = NULL;
    return n;
}

node* insert(node* head, int id, char name[], int value) {
    node* n = createNode(id, name, value);

    if (head == NULL)
        return n;

    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    return head;
}

node* process(node* head) {
    node* temp = head;

    while (temp != NULL && temp->next != NULL) {
        node* next = temp->next;

        int newId = temp->id + next->id;
        int newValue = temp->value + next->value;

        char newName[40];
        strcpy(newName, temp->name);
        strcat(newName, next->name);

        node* newnode = createNode(newId, newName, newValue);

        newnode->next = next->next;
        next->next = newnode;

        temp = newnode->next;
    }

    return head;
}

void display(node* head) {
    while (head != NULL) {
        printf("|_%d_|_%s_|_%d_| --> ", head->id, head->name, head->value);
        head = head->next;
    }
    printf("NULL\n");
}

void destroy(node* head) {
    node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    node* head = NULL;
    int n, id, value;
    char name[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %s %d", &id, name, &value);
        head = insert(head, id, name, value);
    }

    head = process(head);

    display(head);

    destroy(head);
    return 0;
}