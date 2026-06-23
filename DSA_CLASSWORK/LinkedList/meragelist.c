#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct node* next;
    struct node* prev;
}node;

node* create_node(int);
void insert_end(node**, int);
void display(node*);
node* merge_sorted_list(node*,node*);
node* free_list(node*);

int main()
{
    node* head1 = NULL;
    node* head2 = NULL;
    node* marged = NULL;

    insert_end(&head1,1);
    insert_end(&head1,4);
    insert_end(&head1,7);
    insert_end(&head1,10);

    insert_end(&head2,2);
    insert_end(&head2,3);
    insert_end(&head2,8);
    insert_end(&head2,9);

    display(head1);
    display(head2);

    marged = merge_sorted_list(head1,head2);
    printf("Merged List\n");
    display(marged);

    free_list(head1);
    free_list(head2);
    free_list(marged);

    return 0;
}

node* merge_sorted_list(node* head1, node* head2)
{
    node* merge = NULL;
    node* p1 = head1;
    node* p2 = head2;

    while(p1!= NULL && p2!= NULL)
    {
        if(p1->data <= p2->data)
        {
            insert_end(&merge, p1->data);
            p1 = p1->next;
        }
        else{
            insert_end(&merge,p2->data);
            p2 = p2->next;
        }
    }

    while(p1!=NULL)
    {
        insert_end(&merge,p1->data);
        p1 = p1->next;
    }

    while(p2!=NULL)
    {
        insert_end(&merge,p2->data);
        p2 = p2->next;
    }

    return merge;

}

node* create_node(int)
{

}

void insert_end(node**, int)
{

}

void display(node*)
{

}

node* free_list(node*)
{

}










