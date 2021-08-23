#include <stdio.h>
#include <stdlib.h>
#define MAX 25

int stack[MAX];
void push(int x);
int pop();
int isFull();
int isEmpty();
int peek();
void display();
int size();
int top = -1;

void push(int x)
{
    if (isFull())
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {
        stack[++top] = x;
    }
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int isFull()
{
    if (top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int peek()
{
    if (isEmpty())
    {
        printf(("Stack Underflow:\n"));
        exit(0);
    }
    return stack[top];
}

int size()
{
    return top + 1;
}

void display()
{

    int i;
    printf("Top =%d\n", top);
    if (isEmpty())
    {
        printf("stack is Empty : \n");
        return;
    }
    printf("Elements of the stack are:\n");

    for (i = top; i >= 0; i--)
    {
        printf("%d  ", stack[i]);
    }
    printf("\n");
}

int main()
{
    int ch, x;
    while (1)
    {
        printf("1.Insert element in Stack:\n");
        printf("2.Delete element from Stack:\n");
        printf("3.Display element in front:\n");
        printf("4.display all elements in Stack:\n");
        printf("5.display size of Stack :\n");
        printf("6.QUIT:\n");
        scanf("%d", &ch);

        if (ch == 6)
        {
            break;
        }
        switch (ch)
        {
        case 1:
        {
            printf("Enter element to insert:\n");
            scanf("%d", &x);
            push(x);
            break;
        }
        case 2:
        {
            x = pop();
            printf("Element deleted: %d\n\n", x);
            break;
        }
        case 3:
        {
            printf("Element at front is :%d\n\n", peek());

            break;
        }
        case 4:
        {
            display();
            break;
        }
        case 5:
        {
            printf("size of Stack is :%d\n\n", size());

            break;
        }
        default:
        {
            printf("Wrong choice\n\n");
        }

            printf("\n");
        }
    }

    return 0;
}