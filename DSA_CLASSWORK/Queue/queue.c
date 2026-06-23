#include <stdio.h>
#include <stdlib.h>

#define MAX 4
int front = -1;
int rear = -1;

int queue[MAX];

void enqueue(int data)
{
    if (rear == MAX - 1)
    {
        printf("queue is full\n");
    }
    else
    {
        rear++;
        queue[rear] = data;
        if (front == -1)
        {
            front++;
        }
    }
}
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("dequeue element is [%d] \n", queue[front]);
        front++;
    }
}
void display()
{
    if (front == -1 || front > rear)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++)
        {
            printf("[%d ]", queue[i]);
        }
        printf("\n");
    }
}
void isEmpty()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("queue is not empty\n");
    }
}

int main(void)
{
    enqueue(10);
    enqueue(70);
    enqueue(30);
    enqueue(40);
    display();

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    isEmpty();
}