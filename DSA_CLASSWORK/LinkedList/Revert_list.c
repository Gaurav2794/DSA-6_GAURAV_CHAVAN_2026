#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} node;

node* insertAtHead(node* p)
{
    node* p1 = (node*)malloc(sizeof(node));
    if(!p1){
        printf("Memory Allocation failed");
        return p;
    }

    printf("\nEnter no to insert: ");
    scanf("%d", &p1->data);

    p1->next = p;
    p = p1;

    return p;
}

void display(node* p)
{
    if(!p){
        printf("\nList is empty!");
        return;
    }

    printf("\nList contents:");
    while(p != NULL){
        printf(" %d ->", p->data);
        p = p->next;
    }
    printf(" NULL\n");
}

node* Revert_list(node* head)
{
    node* r = NULL;
    node* p = head;
    node* q = NULL;

    while(p != NULL)
    {
        q = p->next;
        p->next = r;
        r = p;
        p = q;
    }

    head = r;
    return head;
}

int main()
{
    node* head = NULL;

    head = insertAtHead(head);
    head = insertAtHead(head);
    head = insertAtHead(head);

    display(head);

    head = Revert_list(head);

    printf("\nAfter Reversing:\n");
    display(head);

    return 0;
}



