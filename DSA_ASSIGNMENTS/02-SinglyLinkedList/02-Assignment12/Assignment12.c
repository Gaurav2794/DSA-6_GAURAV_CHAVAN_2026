/*
write a c program to Create a Singly linked list 
and Delete the node at the last position
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* insert(node* head , int value){
    node* newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL) return head;

    newnode->data = value;
    newnode->next = NULL;

    if(head == NULL)
        return newnode;

    node* temp = head;
    while(temp -> next != NULL)
        temp = temp -> next;

    temp -> next = newnode;
    return head;
}

node* deleteAtEnd(node* head){
    if(head == NULL){
        printf("List is empty\n");
        return NULL;
    }
    if(head->next == NULL){
        free(head);
        return head;
    }
    node* temp = head;
    while(temp-> next->next != NULL)
        temp = temp-> next;
    free(temp->next);
    temp->next = NULL;

    return head;
}
void display(node* head){
    while(head != NULL){
        printf("%d -> ", head->data);
        head = head -> next;
    }
    printf("NULL\n");
}
void destroyList(node* head) {
    node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main(){
    node* head = NULL;
    int n , value;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i = 0 ; i<n ; i++){
        scanf("%d", &value);
        head = insert(head , value);
    }
    printf("Original List: ");
    display(head);

    head = deleteAtEnd(head);

    printf("After deleting last node: ");
    display(head);

    destroyList(head);

    return 0;

}
