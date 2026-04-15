/*
write a c program to Create a Singly linked list and swap the two consecutive nodes        
I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_400_| --> |_5_|_EE_|_500_| --> |_6_|_FF_|_NULL_|  
O/P  ---->   |_2_|_BB_|_100_| --> |_1_|_AA_|_200_| --> |_4_|_DD_|_300_| --> |_3_|_CC_|_400_| --> |_6_|_FF_|_500_| --> |_5_|_EE_|_NULL_|
*/

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

node* insertEnd(node *head, node *newNode) {
    if (head == NULL)
        return newNode;

    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

void display(node *head) {
    while (head != NULL) {
        printf("|_%d_|_%s_|_%d_| --> ",
               head->no, head->name, head->marks);
        head = head->next;
    }
    printf("NULL\n");
}

void alternateSwap(node *head) {
    if (head == NULL || head->next == NULL)
        return;

    node *p = head;

    while (p != NULL && p->next != NULL) {
        node *q = p->next;

        int tempNo = p->no;
        p->no = q->no;
        q->no = tempNo;

        int tempMarks = p->marks;
        p->marks = q->marks;
        q->marks = tempMarks;

        char tempName[50];
        strcpy(tempName, p->name);
        strcpy(p->name, q->name);
        strcpy(q->name, tempName);
        p = q->next;
    }
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

    alternateSwap(head);

    printf("\nAfter Pairwise Swap:\n");
    display(head);

    return 0;
}