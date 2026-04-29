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
    if (!n) exit(1);
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

void search(node* head, int key) {
    node* temp = head;

    while (temp != NULL) {
        if (temp->id == key) {
            printf("|_%d_|_%s_|_%d_|\n", temp->id, temp->name, temp->value);
            return;
        }
        temp = temp->next;
    }

    printf("Not Found\n");
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
    int n, id, value, key;
    char name[20];

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter id name value:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %s %d", &id, name, &value);
        head = insert(head, id, name, value);
    }

    printf("Enter key: ");
    scanf("%d", &key);

    search(head, key);

    destroy(head);
    return 0;
}