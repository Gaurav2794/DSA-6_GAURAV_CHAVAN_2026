/*
write a c program to Create and Display Singly Linked list. with structure "Student" with following data members:
-Name 
-Roll no
-standard
-Division
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char name[50];
    int rollNo;
    int standard;
    char division;
    struct student *next;
}node;
node* createNode() {
    node *newNode = (node*)malloc(sizeof(node));

    printf("\nEnter Name: ");
    scanf(" %[^\n]", newNode->name);

    printf("Enter Roll No: ");
    scanf("%d", &newNode->rollNo);

    printf("Enter Standard: ");
    scanf("%d", &newNode->standard);

    printf("Enter Division: ");
    scanf(" %c", &newNode->division);

    newNode->next = NULL;
    return newNode;
}

node* createList(int n) {
    node *head = NULL, *temp, *newNode;

    for(int i = 0; i < n; i++) {
        newNode = createNode();

        if(head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    return head;
}

void displayList(node *head) {
    node *temp = head;

    if(head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    printf("\n--- Student List ---\n");
    while(temp != NULL) {
        printf("Name: %s | Roll No: %d | Std: %d | Div: %c\n",
               temp->name, temp->rollNo, temp->standard, temp->division);
        temp = temp->next;
    }
}

int main() {
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    node *head = createList(n);

    displayList(head);

    return 0;
}