#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *front = NULL;
struct node *rear = NULL;

int main()
{
    int choice, x;

    // initializeQueue();

    while (1)
    {
        printf("1.Insert element in Queue:\n");
        printf("2.Delete element from Queue:\n");
        printf("3.display element in front:\n");
        printf("4.display all elements in Queue:\n");
        printf("5.display size of queue:\n");
        printf("6.QUIT:\n");
        scanf("%d", &choice);

        if (choice == 6)
        {
            break;
        }
        switch (choice)
        {
        case 1:
        {
            printf("Enter element to enQueue:\n");
            scanf("%d", &x);
            enQueue(x);
            break;
        }
        case 2:
        {
            x = deQueue();
            printf("Element deQueued:%d\n\n", x);
            break;
        }
        case 3:
        {
            printf("Element at front is :%d\n\n", front1());

            break;
        }
        case 4:
        {
            int k;
            printf("Enter value of k: ");
            scanf("%d", &k);
            display();
            dispsort(k);
            break;
        }
        case 5:
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

int size()
{
    int s = 0;
    struct node *p = front;
    while (p != NULL)
    {
        s++;
        p = p->link;
    }
    return s;
}

void enQueue(int x)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory not available: \n");
        return;
    }
    temp->data = x;
    temp->link = NULL;

    if (front == NULL) /* If queue is empty*/
        front = temp;
    else
        rear->link = temp;
    rear = temp;
}

int deQueue()
{
    struct node *temp;

    int x;
    if (isEmpty())
    {
        printf("Queue Underflow: \n");
        exit(1);
    }

    temp = front;
    x = temp->data;
    front = front->link;
    free(temp);
    return x;
}

int front1()
{
    if (isEmpty())
    {
        printf("QUEUE UNDERFLOW:\n");
        exit(1);
    }
    return front->data;
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

    printf("Queue is : \n\n");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->link;
    }

    printf("\n\n");
}
void dispsort(int kk)
{
    // struct node *temp;
    // temp = (struct node *)malloc(sizeof(struct node));
    printf("Modified queue\n");
    struct node *p;
    // int arr[];;
    int arr[10];
    int arr1[10];
    p = front;

    if (isEmpty())
    {
        printf("Queue is Empty: \n");
        return;
    }
    int i = 0, j = 0, k = 0;
    // printf("Queue is : \n\n");
    while (p != NULL)
    {
        if (i < kk)
        {
            arr[i] = p->data;
            i++;
        }
        else
        {
            arr1[k] = p->data;
            k++;
        }

        j++;
        // printf("%d ", p->data);

        p = p->link;
    }

    for (int ii = i - 1; ii >= 0; ii--)
    {
        printf("%d ", arr[ii]);
    }
    for (int ii = 0; ii < k; ii++)
    {
        printf("%d ", arr1[ii]);
    }

    printf("\n\n");
}
