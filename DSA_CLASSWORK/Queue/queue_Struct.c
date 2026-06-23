// queue with struct
#include <stdio.h>
#include <stdlib.h>

#define MAX 4
typedef struct queue
{
    int arr[MAX];
    int front;
    int rear;
} queue;

void enqueue(queue *q, int data)
{
    if (q->rear == MAX - 1)
    {
        printf("queue is full\n");
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = data;
        if (q->front == -1)
        {
            q->front++;
        }
    }
}
void dequeue(queue *q)
{
    if (q->front == -1 || q->front > q->rear)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("dequeue element is [%d] \n", q->arr[q->front]);
        q->front++;
    }
}
void display(queue *q)
{
    if (q->front == -1 || q->front > q->rear)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("Queue elements are: ");
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("[%d ]", q->arr[i]);
        }
        printf("\n");
    }
}

int main(void)
{
    queue q;
    q.front = -1;
    q.rear = -1;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    display(&q);
    dequeue(&q);
}
