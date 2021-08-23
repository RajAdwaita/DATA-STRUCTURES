#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int a[MAX];
int front, rear;

void initializeQueue();
int isFull();
int isEmpty();
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

int isEmpty()
{
    if (front == -1 || front == rear + 1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (rear == MAX - 1)
        return 1;
    else
        return 0;
}

int size()
{
    if (isEmpty())
        return 0;
    else
        return rear - front + 1;
}

void insert(int x)
{
    if (isFull())
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
    if (isEmpty())
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

    if (isEmpty())
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
