#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}n;

void create (n*head){
    n*start= NULL;
    n*p;
    int choice;
    do{
        n*p=(n*)malloc(sizeof(n));
        printf("Enter data: ");
        scanf("%d", &p->data);
        if(head== NULL){
            head=p;
            start=head;
        }
        else{
            start->next=p;
            start=start->next;
        }  
      
    }    
    while(choice);
    head->next=NULL;
}
void display(n*p){
        while(p!= NULL){
            printf("%d -> ", p->data);
            p=p->next;
        }
        printf("NULL\n");
}
void AddNodeAtFirst(n*p){
        n*newNode=(n*)malloc(sizeof(n));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->next=p;
        while(p->next!= NULL){
            p=p->next;
        }
        p->next=newNode;
}
void AddNodeAtLast(n*p){
        n*newNode=(n*)malloc(sizeof(n));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        while(p->next!= NULL){
            p=p->next;
        }
        p->next=newNode;
}
int main(){
    n*head= NULL;
    create(head);
    display(head);
    AddNodeAtFirst(head);
    display(head);
    AddNodeAtLast(head);
    display(head);
}



   