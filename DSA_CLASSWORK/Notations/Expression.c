/*
Algorithm
1,start
2, input infix expression
3,initilize
   to stack
   array - operator stack[] for each operator
   array - operand stack[] for 2D array of strings
         for storing postfix expressions

for each ch in string s from lesf to right, repeat 5 t0 10 
5, if ch is a operand or number increment  top 2
    push ch to operand stack[top2]
6,else if ch is "(" push ch to operator stack[top1]
7,else if ch is ")" 
    while operator stack[top1] is not "("
        pop operator from operator stack and store in op
        pop operand1 from operand stack and store in op1
        pop operand2 from operand stack and store in op2
        create new string temp = op + op2 + op1
        push temp to operand stack[top2]
    pop "(" from operator stack)
8,else if ch is an operator
    while operator stack is not empty and precedence of ch <= precedence of operator stack[top1]
        pop operator from operator stack and store in op
        pop two operands from operand stack combine two resent index and push
        that result back to operand stack[top2]

9,after the loop if operator stack is not empty repeat step 8

10, after all ch are proceed
    while(top 1 > = 0;)
    pop operator from operator stack and store in op
    pop operand1 from operand stack and store in op1
    pop operand2 from operand stack and store in op2
    create new string temp = op + op2 + op1
    push temp to operand stack[top2]

11, finally postfix expression is operand stack[top2]

12,Display the result
13,stop


   */

#include<stdio.h>
#include<string.h>

#define MAX 100

char operator_stack[MAX];
char operand_stack[MAX][MAX];

int top1 = -1;
int top2 = -1;

int precedence(char op)
{
    if(op == '+' || op == '-')
        return 1;

    if(op == '*' || op == '/')
        return 2;

    return 0;
}

void push_operator(char ch)
{
    operator_stack[++top1] = ch;
}

char pop_operator()
{
    return operator_stack[top1--];
}

void push_operand(char str[])
{
    strcpy(operand_stack[++top2], str);
}

char* pop_operand()
{
    return operand_stack[top2--];
}

char* infix_to_prefix(char infix[])
{
    int i;
    char ch;

    for(i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        // Operand
        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        {
            char temp[2];

            temp[0] = ch;
            temp[1] = '\0';

            push_operand(temp);
        }

    
        else if(ch == '(')
        {
            push_operator(ch);
        }

     
        else if(ch == ')')
        {
            while(operator_stack[top1] != '(')
            {
                char op = pop_operator();

                char *op1 = pop_operand();
                char *op2 = pop_operand();

                char temp[MAX];

                temp[0] = op;
                temp[1] = '\0';

                strcat(temp, op2);
                strcat(temp, op1);

                push_operand(temp);
            }

            pop_operator(); 
        }

       
        else
        {
            while(top1 != -1 &&
                  precedence(ch) <= precedence(operator_stack[top1]))
            {
                char op = pop_operator();

                char *op1 = pop_operand();
                char *op2 = pop_operand();

                char temp[MAX];

                temp[0] = op;
                temp[1] = '\0';

                strcat(temp, op2);
                strcat(temp, op1);

                push_operand(temp);
            }

            push_operator(ch);
        }
    }

    while(top1 != -1)
    {
        char op = pop_operator();

        char *op1 = pop_operand();
        char *op2 = pop_operand();

        char temp[MAX];

        temp[0] = op;
        temp[1] = '\0';

        strcat(temp, op2);
        strcat(temp, op1);

        push_operand(temp);
    }

    return operand_stack[top2];
}

int main()
{
    char infix[MAX];

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    printf("Prefix Expression: %s", infix_to_prefix(infix));

    return 0;
}