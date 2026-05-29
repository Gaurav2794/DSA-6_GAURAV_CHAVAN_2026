#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int stack[MAX];
int top = -1;

//check if stack is empty
int isEmpty(){return (top == -1);}
//check if stack is full
int isFull(){return (top ==MAX-1);}

//push Function
void push(int value)
{
    if(isFull()){
        printf("Stack Overflow\n");
        return ;
    }
    top++;
    stack[top]=value;
    printf("%d pushed to stack\n",value);
}

//pop Function
void pop()
{
    if(isEmpty()){
        printf("Stack Underflow\n");
        return ;
    }
    printf("%d popped from stack\n",stack[top]);
    top--;
}

//display operation
void display()
{
    
    if(isEmpty()){
        printf("Stack is empty\n");
        return ;
    }
    printf("\nStack elements are: \n");
    for(int i = top ; i>=0 ;i--){
        printf("%d\n",stack[i]);
    }
}
void peek()
{
    if(isEmpty()){
        printf("Stack is empty\n");
        return ;
    }
    printf("\nTop element is: %d\n",stack[top]);

}


//main Function
int main()
{
    push(10);
    push(20);
    push(30);
    
    push(60);

    display();

    peek();

    pop();
    pop();

    display();

    return 0;
}