/*
write a c program to Create Doubly linked list and Display it.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node *insertEnd(Node *head, int value)
{
    Node *newNode = createNode(value);

    if (head == NULL)
    {
        return newNode;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

void display(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    Node *head = NULL;

    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);

    display(head);

    return 0;
}

