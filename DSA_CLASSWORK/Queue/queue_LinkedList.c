#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct queue
{
    node *front;
    node *rear;
} queue;

void enqueue(queue *q, int data)
{

    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;

    if (q->rear == NULL)
    {
        q->front = newnode;
        q->rear = newnode;
    }
    else
    {

        q->rear->next = newnode;
        q->rear = newnode;
    }
}
void dequeue(queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        node *temp = q->front;
        printf("Dequeue element is [%d] \n", temp->data);
        q->front = q->front->next;
        free(temp);
    }
}
void display(queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        node *temp = q->front;
        printf("Queue elements are: ");
        while (temp != NULL)
        {
            printf("[%d ]", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }      
}
void destroy(queue *q){
    node *temp = q-> front;
    while(temp != NULL){
        node *next = temp -> next ;
        free(temp);
        temp = next;
    }
    printf("List is destroyed !!");
}     

int main(void)
{
    queue q;
    q.front = NULL;
    q.rear = NULL;
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30); 
    enqueue(&q,60);
    enqueue(&q,80);
    display(&q);
    display(&q);
    dequeue(&q);
    display(&q);
    dequeue(&q);
    display(&q);
    dequeue(&q);
    display(&q);
    dequeue(&q);
    display(&q);
    dequeue(&q);
    display(&q);
    destroy(&q);
    return 0;
}