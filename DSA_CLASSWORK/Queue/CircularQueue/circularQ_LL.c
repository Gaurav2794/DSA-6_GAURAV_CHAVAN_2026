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

    if (q->front == NULL)
    {
        q->front = q->rear = newnode;
        newnode->next = q->front;
    }
    else
    {
        newnode->next = q->front;
        q->rear->next = newnode;
        q->rear = newnode;
    }
}

void dequeue(queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    node *temp = q->front;

    if (q->front == q->rear)
    {
        printf("Dequeued element is [%d]\n", temp->data);
        q->front = q->rear = NULL;
        free(temp);
    }
    else
    {
        printf("Dequeued element is [%d]\n", temp->data);
        q->front = q->front->next;
        q->rear->next = q->front;
        free(temp);
    }
}

void display(queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    node *temp = q->front;
    printf("[Front] -> ");

    do
    {
        printf("[%d] -> ", temp->data);
        temp = temp->next;
    } while (temp != q->front);

    printf("[Rear]\n");
}

int main()
{
    queue q = {NULL, NULL};

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display(&q);

    dequeue(&q);
    display(&q);

    dequeue(&q);
    display(&q);

    enqueue(&q, 50);
    display(&q);

    return 0;
}