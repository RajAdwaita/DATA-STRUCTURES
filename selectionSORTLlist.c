#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

//I dont want to traverse for add an item last position, i will use last->next
struct node *last = NULL;
struct node *temp;

struct node *createNode(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void addLast(int y)
{
    struct node *hodor = createNode(y);
    if (start == NULL)
    {
        start = hodor;
        last = hodor;
    }
    else
    {
        last->next = hodor;
        last = hodor;
    }
}

void printLinked()
{
    temp = start;
    while (temp->next != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

void init(int size)
{
    printf("Enter the values : \n ");
    int i, number;
    for (i = 0; i < size; i++)
    {
        scanf("%d", &number);
        addLast(number);
    }
}

void selectionLinked()
{
    struct node *key;
    key = start;

    while (key != NULL)
    {
        temp = key->next;
        while (temp != NULL)
        {
            if (key->data > temp->data)
            {
                swapNode(key, temp);
            }
            temp = temp->next;
        }
        key = key->next;
    }
}

void swapNode(struct node *x, struct node *y)
{
    int temp = x->data;
    x->data = y->data;
    y->data = temp;
}

int main()
{

    int choise;

    printf("\n How many numbers do you want to create ... ");
    scanf("%d", &choise);
    init(choise);
    selectionLinked();
    printf("The sorted List is: \n");
    printLinked();
}