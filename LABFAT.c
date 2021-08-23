#include <stdio.h>
#include <stdlib.h>
#define MAX 25

int stack[MAX];
int n;
int sum;
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
    int n, k;
    printf("%d %d", &n, &k);

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

        case 4:
        {
            display();
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
int a[MAX];
int front, rear;

void initializeQueue();
int isFullq();
int isEmptyq();
int size();
void insert(int x);
int Delete();
void display();
int main()
{
    int choice, x;

    initializeQueue();

    while (1)
    {
        printf("1.Insert element in Queue:\n");
        printf("2.Delete element from Queue:\n");
        printf("3.display all elements in Queue:\n");
        printf("4.display size of queue:\n");
        printf("5.QUIT:\n");
        scanf("%d", &choice);

        if (choice == 5)
        {
            break;
        }
        switch (choice)
        {
        case 1:
        {
            printf("Enter element to insert:\n");
            scanf("%d", &x);
            insert(x);
            break;
        }
        case 2:
        {
            x = Delete();
            printf("Element deleted:%d\n\n", x);
            break;
        }

        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            printf("size of queue is :%d\n\n", size());

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

void initializeQueue()
{

    rear = front = -1;
}

int isEmptyq()
{
    if (front == -1 || front == rear + 1)
        return 1;
    else
        return 0;
}

int isFullq()
{
    if (rear == MAX - 1)
        return 1;
    else
        return 0;
}

int size()
{
    if (isEmptyq())
        return 0;
    else
        return rear - front + 1;
}

void insert(int x)
{
    if (isFullq())
    {
        printf("Queue Full:\n\n");
        return;
    }
    if (front == -1)
        front = 0;

    a[++rear] = x;
}

int Delete()
{
    int x;
    if (isEmptyq())
    {
        printf("Queue Empty:\n\n");
        exit(1);
    }
    x = a[front];
    front++;
    return x;
}

void display()
{
    int i;

    if (isEmptyq())
    {
        printf("Queue Empty:\n");
        return;
    }

    printf("QUEUE IS :\n\n");

    for (int i = front; i <= rear; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\n\n");
}
