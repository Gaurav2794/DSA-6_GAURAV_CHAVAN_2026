/*
write a c program to Create a Singly linked list and Display the alternate nodes 

I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_400_| --> |_5_|_EE_|_NULL_|. 

O/P  ---->  |_1_|_AA_|_100_| --> |_3_|_CC_|_300_| --> |_5_|_EE_|_NULL_|*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int no;
    char name[50];
    int marks;
    struct node* next;
} node;

node* createNode(int no, char name[], int marks) {
    node *n = (node*)malloc(sizeof(node));
    n->no = no;
    strcpy(n->name, name);
    n->marks = marks;
    n->next = NULL;
    return n;
}

void display(node *head) {
    while (head != NULL) {
        printf("|_%d_|_%s_|_%d_| --> ",
               head->no, head->name, head->marks);
        head = head->next;
    }
    printf("NULL\n");
}

void displayAlternate(node *head) {
    node *p = head;

    while (p != NULL) {
        printf("|_%d_|_%s_|_%d_| --> ",
               p->no, p->name, p->marks);

        if (p->next == NULL)
            break;

        p = p->next->next;
    }
    printf("NULL\n");
}

int main() {
    node *head = createNode(1, "AA", 100);
    head->next = createNode(2, "BB", 200);
    head->next->next = createNode(3, "CC", 300);
    head->next->next->next = createNode(4, "DD", 400);
    head->next->next->next->next = createNode(5, "EE", 500);
    head->next->next->next->next->next = createNode(6, "FF", 600);

    printf("Original List:\n");
    display(head);

    printf("\nAlternate Nodes:\n");
    displayAlternate(head);

    return 0;
}