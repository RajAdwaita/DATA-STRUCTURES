#include <stdio.h>
#include <stdlib.h>

struct node

{
    int info;
    struct node *link;
};

struct node *createList(struct node *last);
void displayList(struct node *last);
struct node *insertInEmptyList(struct node *start, int data);
struct node *insertInBeginning(struct node *last, int data);
struct node *insertAtEnd(struct node *last, int data);
struct node *insertAfter(struct node *last, int data, int x);
struct node *deleteNode(struct node *last, int data);

int main()
{

    struct node *last = NULL;
    int choice, data, item;

    last = createList(last);

    while (1)
    {

        printf("\n");
        printf("1.Display list:\n ");
        printf("2.Insert in empty List:\n ");
        printf("3.Insert a node at the beginning of the list:\n ");
        printf("4.Insert a node at the end of the list:\n ");
        printf("5.Insert a node after a specified node:\n ");
        printf("6.Delete node:\n ");
        printf("7.Quit:\n ");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 7)
            break;

        switch (choice)
        {

        case 1:
        {
            displayList(last);
            break;
        }
        case 2:
        {
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            last = insertInEmptyList(last, data);
            break;
        }
        case 3:
        {
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            last = insertInBeginning(last, data);
            break;
        }
        case 4:
        {
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            last = insertAtEnd(last, data);
            break;
        }
        case 5:
        {
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            printf("Enter the element after which to insert: ");
            scanf("%d", &item);
            last = insertAfter(last, data, item);
            break;
        }

        case 6:
        {
            printf("Enter the element to be deleted: ");
            scanf("%d", &data);
            last = deleteNode(last, data);
            break;
        }

        default:
        {
            printf("Wrong Choice: \n");
        }
        }
    }
    return 0;
}

void displayList(struct node *last)
{
    struct node *p;
    if (last == NULL)
    {
        printf("List is empty:\n");
        return;
    }

    printf("List is : ");

    p = last->link;
    do
    {

        printf("%d   ", p->info);
        p = p->link;
    } while (p != last->link);
    printf("\n");
}

struct node *insertInEmptyList(struct node *last, int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    last = temp;
    last->link = last;

    return last;
}

struct node *insertInBeginning(struct node *last, int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;

    temp->link = last->link;
    last->link = temp;

    return last;
}

struct node *insertAtEnd(struct node *last, int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->link = last->link;
    last->link = temp;
    last = temp;
    return last;
}

struct node *createList(struct node *last)
{
    int i, n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    last = NULL;

    if (n == 0)
    {
        return last;
    }
    printf("Enter the first element to be inserted: ");
    scanf("%d", &data);
    last = insertInEmptyList(last, data);

    for (i = 2; i <= n; i++)
    {
        printf("Enter the next element to be inserted: ");
        scanf("%d", &data);
        last = insertAtEnd(last, data);
    }
    return last;
}

struct node *insertAfter(struct node *last, int data, int x)
{
    struct node *temp, *p;

    p = last->link;
    do
    {

        if (p->info == x)
            break;
        p = p->link;
    } while (p != last->link);
    if (p == last->link && p->info != x)
        printf("%d not present in the list: \n", x);
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->info = data;
        temp->link = p->link;
        p->link = temp;
        if (p == last)
            last = temp;
    }
    return last;
}

struct node *deleteNode(struct node *last, int x)
{
    struct node *temp, *p;
    if (last == NULL)
    {
        printf("List is empty: \n");
        return last;
    }

    if (last->link == last && last->info == x)
    {

        temp = last;
        last = NULL;
        free(temp);
        return last;
    }

    if (last->link->info == x)
    {
        temp = last->link;
        last->link = temp->link;
        last->link = NULL;
        free(temp);
        return last;
    }

    p = last->link;
    while (p->link != last)
    {
        if (p->link->info == x)
            break;
        p = p->link;
    }

    if (p->link != last)
    {
        temp = p->link;
        p->link = temp->link;
        free(temp);
    }

    else
    {
        if (last->info == x)
        {
            temp = last;
            p->link = last->link;
            last = p;
            free(temp);
        }
        else
        {
            printf("Element %d not found\n", x);
        }
    }
    return last;
}
