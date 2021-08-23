#include <stdio.h>
#include <stdlib.h>

struct node
{
    int priority;
    int info;
    struct node *link;
};

struct node *front = NULL;

void initializeQueue();
void insert(int element, int elementPriority);
int Delete();
void display();
int isEmpty();

int main()
{
    int choice, element, elementPriority, x;

    initializeQueue();

    while (1)
    {
        printf("1.Insert element in Queue:\n");
        printf("2.Delete element from Queue:\n");
        printf("3.display all elements in Queue:\n");
        printf("4.QUIT:\n");
        scanf("%d", &choice);

        if (choice == 4)
        {
            break;
        }
        switch (choice)
        {
        case 1:
        {
            printf("Enter element to insert:\n");
            scanf("%d", &element);
            printf("Enter it's priority:\n ");
            scanf("%d", &elementPriority);
            insert(element, elementPriority);
            ;
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

    front = NULL;
}

void insert(int element, int elementPriority)
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory not available: \n");
        return;
    }
    temp->info = element;
    temp->priority = elementPriority;

    if (isEmpty() || elementPriority < front->priority)
    {
        temp->link = front;
        front = temp;
    }
    else
    {

        p = front;
        while (p->link != NULL && p->link->priority <= elementPriority)
            p = p->link;

        temp->link = p->link;
        p->link = temp;
    }
}

int Delete()
{
    struct node *temp;

    int element;
    if (isEmpty())
    {
        printf("Queue Underflow: \n");
        exit(1);
    }
    else
    {
        temp = front;
        element = temp->info;
        front = front->link;
        free(temp);
    }

    return element;
}

int isEmpty()
{
    if (front == NULL)
        return 1;
    else
        return 0;
}

void display()
{
    struct node *p;
    p = front;

    if (isEmpty())
    {
        printf("Queue is Empty: \n");
        return;
    }

    else
    {
        printf("Queue is : \n\n");
        printf("Priority      element\n");
        while (p != NULL)

        {
            printf("%5d        %5d\n", p->priority, p->info);
            p = p->link;
        }
    }

    printf("\n\n");
}