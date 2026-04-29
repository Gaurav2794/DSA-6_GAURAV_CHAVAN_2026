/*
 
 	
write a c program to Create a Singly linked list and Display it in reverse order (Use Normal Function)
I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_| 
O/P :
------  
4 DD
3 CC
2 BB
1 AA
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int id;
    char name[20];
    struct node* next;
} node;

node* insert(node* head, int id, char name[]) {
    node* newnode = (node*)malloc(sizeof(node));
    if (newnode == NULL) return head;

    newnode->id = id;
    strcpy(newnode->name, name);
    newnode->next = NULL;

    if (head == NULL)
        return newnode;

    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    return head;
}

void display(node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (head != NULL) {
        printf("%d %s -> ", head->id, head->name);
        head = head->next;
    }
    printf("NULL\n");
}

void displayReverse(node* head) {
    int ids[100], top = -1;
    char names[100][20];

    node* temp = head;

    while (temp != NULL) {
        ids[++top] = temp->id;
        strcpy(names[top], temp->name);
        temp = temp->next;
    }

    while (top >= 0) {
        printf("%d %s\n", ids[top], names[top]);
        top--;
    }
}

void destroyList(node* head) {
    node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    node* head = NULL;
    int n, id;
    char name[20];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter id and name:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %s", &id, name);
        head = insert(head, id, name);
    }

    printf("\nList:\n");
    display(head);

    printf("\nReverse Order:\n");
    displayReverse(head);

    destroyList(head);

    return 0;
}