#include <stdio.h>
#include <stdlib.h>

struct node

{
    struct node *prev;
    int info;
    struct node *link;
};

struct node *createList(struct node *head);
void displayList(struct node *head);
struct node *insertInEmptyList(struct node *start, int data);
struct node *insertInBeginning(struct node *head, int data);
void insertAtEnd(struct node *head, int data);
void insertAfter(struct node *head, int data, int x);
struct node *insertBefore(struct node *head, int data, int x);
struct node *deleteNode(struct node *head, int data);
struct node *reverseList(struct node *head);
struct node *insertAtPosition(struct node *head, int data, int k);

int main()
{

    struct node *head = NULL;
    int choice, data, x, k;

    head = createList(head);

    while (1)
    {

        printf("\n");
        printf("1.Display list:\n ");
        printf("2.Insert in empty List:\n ");
        printf("3.Insert a node at the beginning of the list:\n ");
        printf("4.Insert a node at the end of the list:\n ");
        printf("5.Insert a node after a specified node:\n ");
        printf("6.Insert a node before a specified node:\n ");
        printf("7.Delete node:\n ");
        printf("8.Reverse the list:\n ");
        printf("9.Quit:\n ");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 9)
            break;

        switch (choice)
        {

        case 1:
        {
            displayList(head);
            break;
        }
        case 2:
        {
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            head = insertInEmptyList(head, data);
            break;
        }
        case 3:
        {
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            head = insertInBeginning(head, data);
            break;
        }
        case 4:
        {
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            insertAtEnd(head, data);
            break;
        }
        case 5:
        {
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            printf("Enter the element after which to insert: ");
            scanf("%d", &x);
            insertAfter(head, data, x);
            break;
        }
        case 6:
        {
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            printf("Enter the element before which to insert: ");
            scanf("%d", &x);
            head = insertBefore(head, data, x);
            break;
        }
        case 7:
        {
            printf("Enter the element to be deleted: ");
            scanf("%d", &data);
            head = deleteNode(head, data);
            break;
        }
        case 8:
        {
            head = reverseList(head);
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

void displayList(struct node *head)
{
    struct node *p;
    if (head == NULL)
    {
        printf("List is empty:\n");
        return;
    }

    printf("List is : ");

    p = head;
    while (p != NULL)
    {
        printf("%d   ", p->info);
        p = p->link;
    }
    printf("\n");
}

struct node *insertInEmptyList(struct node *head, int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->prev = NULL;

    temp->link = NULL;
    head = temp;

    return head;
}

struct node *insertInBeginning(struct node *head, int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->prev = NULL;

    temp->link = head;
    head = temp;

    return head;
}

void insertAtEnd(struct node *head, int data)
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    p = head;
    while (p->link != NULL)
        p = p->link;
    p->link = temp;
    temp->link = NULL;
    temp->prev = p;
}

struct node *createList(struct node *head)
{
    int i, n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n == 0)
    {
        return head;
    }
    printf("Enter the first element to be inserted: ");
    scanf("%d", &data);
    head = insertInEmptyList(head, data);

    for (i = 2; i <= n; i++)
    {
        printf("Enter the next element to be inserted: ");
        scanf("%d", &data);
        insertAtEnd(head, data);
    }
    return head;
}

void insertAfter(struct node *head, int data, int x)
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;

    p = head;
    while (p != NULL)
    {

        if (p->info == x)
            break;
        p = p->link;
    }
    if (p == NULL)
        printf("%d not present in the list: \n", x);
    else
    {
        // temp = (struct node *)malloc(sizeof(struct node));
        temp->prev = p;
        temp->link = p->link;
        if (p->link != NULL)
            p->link->prev = temp;

        p->link = temp;
    }
}

struct node *insertBefore(struct node *head, int data, int x)
{
    struct node *temp, *p;
    /* LIST IS EMPTY*/
    if (head == NULL)
    {
        printf("List is empty:I\n");
        return head;
    }
    if (x == head->info)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->info = data;
        temp->prev = NULL;
        temp->link = head;
        head->prev = temp;
        head = temp;
        return head;
    }

    p = head;
    while (p != NULL)
    {

        if (p->info == x)
            break;
        p = p->link;
    }

    if (p == NULL)
        printf("%d not present in the list\n:", x);
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->info = data;
        temp->prev = p->prev;
        temp->link = p;
        p->prev->link = temp;
        p->prev = temp;
    }
    return head;
}

struct node *deleteNode(struct node *head, int x)
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty: \n");
        return head;
    }
    /*Deletion of first node*/
    if (head->link == NULL)
    {
        if (head->info == x)
        {
            temp = head;
            head = NULL;
            free(temp);
        }
        else
        {
            printf("Element %d not in list: \n\n", x);
            return head;
        }
    }

    if (head->info == x)
    {
        temp = head;
        head = head->link;
        head->prev = NULL;
        free(temp);
        return head;
    }

    temp = head->link;
    while (temp->link != NULL)
    {
        if (temp->info == x)
            break;
        temp = temp->link;
    }

    if (temp->link != NULL)
    {
        temp->prev->link = temp->link;
        temp->link->prev = temp->prev;
        free(temp);
    }

    else
    {
        if (temp->info == x)
        {
            temp->prev->link = NULL;
            free(temp);
        }
        else
        {
            printf("Element %d not found\n", x);
        }
    }
    return head;
}

struct node *reverseList(struct node *head)
{
    struct node *p1, *p2;
    if (head == NULL)
    {
        return;
    }
    p1 = head;
    p2 = p1->link;
    p1->link = NULL;
    p1->prev = p2;
    while (p2 != NULL)
    {
        p2->prev = p2->link;
        p2->link = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    head = p1;
    return head;
}
