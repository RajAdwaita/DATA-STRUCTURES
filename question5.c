#include <stdio.h>
#include <stdlib.h>

struct node

{
    int info;
    struct node *link;
};

struct node *createList(struct node *head);
void displayList(struct node *head);
void countNodes(struct node *head);
void search(struct node *head);
struct node *insertInBeginning(struct node *head, int data);
void insertAtEnd(struct node *head, int data);
void insertAfter(struct node *head, int data, int x);
struct node *insertBefore(struct node *head, int data, int x);
struct node *insertAtPosition(struct node *head, int data, int k);
struct node *deleteNode(struct node *head, int data);
struct node *reverseList(struct node *head);

int main()
{

    struct node *head = NULL;
    int choice, data, x, k;

    head = createList(head);

    while (1)
    {

        printf("\n");
        printf("1.Display list:\n ");
        printf("2.Count the number of nodes:\n ");
        printf("3.Search for negative element and delete successor :\n ");
        printf("4.Insert in empty List / Insert in the beginning of the list:\n ");
        printf("5.Insert a node at the end of the list:\n ");
        printf("6.Insert a node after a specified node:\n ");
        printf("7.Insert a node before a specified node:\n ");
        printf("8.Insert a node at a given position:\n ");
        printf("9.Delete node:\n ");
        printf("10.Reverse the list:\n ");
        printf("11.Quit:\n ");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 11)
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
            countNodes(head);
            break;
        }
        case 3:
        {

            search(head);
            break;
        }
        case 4:
        {
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            head = insertInBeginning(head, data);
            break;
        }
        case 5:
        {
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            insertAtEnd(head, data);
            break;
        }
        case 6:
        {
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            printf("Enter the element after which to insert: ");
            scanf("%d", &x);
            insertAfter(head, data, x);
            break;
        }
        case 7:
        {
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            printf("Enter the element before which to insert: ");
            scanf("%d", &x);
            head = insertBefore(head, data, x);
            break;
        }
        case 8:
        {
            printf("Enter the element to be deleted: ");
            scanf("%d", &data);
            printf("Enetr the position at which to enter:\n");
            scanf("%d", &k);
            head = insertAtPosition(head, data, k);

            break;
        }
        case 9:
        {
            printf("Enter the element to be deleted: ");
            scanf("%d", &data);
            head = deleteNode(head, data);
            break;
        }
        case 10:
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
    head = insertInBeginning(head, data);

    for (i = 2; i <= n; i++)
    {
        printf("Enter the next element to be inserted: ");
        scanf("%d", &data);
        insertAtEnd(head, data);
    }
    return head;
}

struct node *insertInBeginning(struct node *head, int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;

    temp->link = head;
    head = temp;

    return head;
}

void insertAtEnd(struct node *head, int data)
{
    struct node *p, *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;

    p = head;
    while (p->link != NULL)
    {
        p = p->link;
    }

    p->link = temp;
    temp->link = NULL;
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

void countNodes(struct node *head)
{
    int n = 0;
    struct node *p = head;
    while (p != NULL)
    {
        n++;
        p = p->link;
    }
    printf("Number of nodes in the list = %d\n ", n);
}

void search(struct node *head)
{
    struct node *p;
    int pos = 1;
    p = head;
    while (p != NULL)
    {
        if (p->info < 0)
        {
            int tem = p->link->info;
            head = deleteNode(head, tem);
        }
        pos++;
        p = p->link;
    }
}

void insertAfter(struct node *head, int data, int x)
{
    struct node *temp, *p;

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
        temp = (struct node *)malloc(sizeof(struct node));
        temp->info = data;
        temp->link = p->link;
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
        temp->link = head;
        head = temp;
        return head;
    }

    p = head;
    while (p->link != NULL)
    {

        if (p->link->info == x)
            break;
        p = p->link;
    }

    if (p->link == NULL)
        printf("%d not present in the list\n:", x);
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->info = data;
        temp->link = p->link;
        p->link = temp;
    }
    return head;

    if (x == head->info)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->info = data;
        temp->link = head;
        head = temp;
        return head;
    }

    p = head;
    while (p->link != NULL)
    {
        if (p->link->info == x)
            break;
        p = p->link;
    }

    if (p->link == NULL)
    {
        printf("%d not present in the list: \n", x);
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->info = data;
        temp->link = p->link;
        p->link = temp;
    }
    return head;
}

struct node *insertAtPosition(struct node *head, int data, int k)
{
    struct node *temp, *p;
    int i;

    if (k == 1)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->info = data;
        temp->link = head;
        head = temp;
        return head;
    }

    p = head;
    for (int i = 1; i < k - 1 && p != NULL; i++)
        p = p->link;
    if (p == NULL)
        printf("You can insert only upto %dth position: \n\n", i);
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->info = data;
        temp->link = p->link;
        p->link = temp;
    }
    return head;
}

struct node *deleteNode(struct node *head, int x)
{
    struct node *temp, *p;
    if (head == NULL)
    {
        printf("List is empty: \n");
        return head;
    }
    /*Deletion of first node*/
    if (head->info == x)
    {
        temp = head;
        head = head->link;
        free(temp);
        return head;
    }

    /* Deletion in between or at the end*/
    p = head;
    while (p->link != NULL)
    {
        if (p->link->info == x)
            break;
        p = p->link;
    }

    if (p->link == NULL)
    {
        printf("Element %d not in list: \n\n", x);
    }
    else
    {
        temp = p->link;
        p->link = temp->link;
        free(temp);
    }
    return head;
}

struct node *reverseList(struct node *head)
{
    struct node *prev, *ptr, *next;
    prev = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        next = ptr->link;
        ptr->link = prev;
        prev = ptr;
        ptr = next;
    }
    head = prev;
    return head;

} /*End of reverseList()*/
