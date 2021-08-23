#include <stdio.h>
#include <stdlib.h>

struct node

{
    int info;
    struct node *link;
};

void createList(struct node *head);
void displayList(struct node *head);
// void countNodes(struct node *head);
// void search(struct node *head, int x);
// struct node *insertInBeginning(struct node *head, int data);
void insertAtEnd(struct node *head, int data);
// void insertAfter(struct node *head, int data, int x);
void insertBefore(struct node *head, int data, int x);
void insertAtPosition(struct node *head, int data, int k);
void deleteNode(struct node *head, int data);
void reverse(struct node *head);

int main()
{

    struct node *head;
    int choice, data, x, k;

    head = (struct node *)malloc(sizeof(struct node));
    head->info = 0;
    head->link = NULL;
    createList(head);

    while (1)
    {

        printf("\n");
        printf("1.Display list:\n ");
        // printf("2.Count the number of nodes:\n ");
        // printf("3.Search for an element:\n ");
        // printf("4.Add to an empty list / at the beginning:\n ");
        printf("2.Add a node at the end of the list:\n ");
        // printf("6.Add a node after a specified node:\n ");
        printf("3.Add a node before a specified node:\n ");
        printf("4.Add a node at a specified position:\n ");
        printf("5.Delete a node:\n ");
        printf("6.Reverse the list:\n ");
        printf("7.QUIT:\n\n ");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 7)
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
            printf("Enter the element to be inserted at the end: ");
            scanf("%d", &data);
            insertAtEnd(head, data);
            break;
        }
        case 3:
        {
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            printf("Enter the element before which to insert: ");
            scanf("%d", &x);
            insertBefore(head, data, x);
            break;
        }
        case 4:
        {
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            printf("Enter the position at which to insert: ");
            scanf("%d", &k);
            insertAtPosition(head, data, k);
            break;
        }
        case 5:
        {
            printf("Enter the element to be deleted: ");
            scanf("%d", &data);
            deleteNode(head, data);
            break;
        }
        case 6:
        {
            reverse(head);
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
    if (head->link == NULL)
    {
        printf("List is empty:\n");
        return;
    }

    printf("List is : ");

    p = head->link;
    while (p != NULL)
    {
        printf("%d   ", p->info);
        p = p->link;
    }
    printf("\n");
}

// void countNodes(struct node *head)
// {
//     int n = 0;
//     struct node *p = head;
//     while (p != NULL)
//     {
//         n++;
//         p = p->link;
//     }
//     printf("Number of nodes in the list = %d\n ", n);
// }

// void search(struct node *head, int x)
// {
//     struct node *p;
//     int pos = 1;
//     p = head;
//     while (p != NULL)
//     {
//         if (p->info == x)
//         {
//             break;
//         }
//         pos++;
//         p = p->link;
//     }

//     if (p == NULL)
//     {
//         printf("%d is not found in the list: \n", x);
//     }
//     else
//     {
//         printf("%d is found in the list and at position %d", x, pos);
//     }
// }

void createList(struct node *head)
{
    int i, n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // if (n == 0)
    // {
    //     return head;
    // }
    // printf("Enter the first element to be inserted: ");
    // scanf("%d", &data);
    // head = insertInBeginning(head, data);

    for (i = 1; i <= n; i++)
    {
        printf("Enter the next element to be inserted: ");
        scanf("%d", &data);
        insertAtEnd(head, data);
    }
}

// struct node *insertInBeginning(struct node *head, int data)
// {
//     struct node *temp;
//     temp = (struct node *)malloc(sizeof(struct node));
//     temp->info = data;

//     temp->link = head;
//     head = temp;

//     return head;
// }

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

// void insertAfter(struct node *head, int data, int x)
// {
//     struct node *temp, *p;

//     p = head;
//     while (p != NULL)
//     {

//         if (p->info == x)
//             break;
//         p = p->link;
//     }
//     if (p == NULL)
//         printf("%d not present in the list: \n", x);
//     else
//     {
//         temp = (struct node *)malloc(sizeof(struct node));
//         temp->info = data;
//         temp->link = p->link;
//         p->link = temp;
//     }
// }

void insertBefore(struct node *head, int data, int x)
{
    struct node *temp, *p;

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
}

void insertAtPosition(struct node *head, int data, int k)
{
    struct node *temp, *p;
    int i;

    p = head;
    for (int i = 1; i <= k - 1 && p != NULL; i++)
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
}

void deleteNode(struct node *head, int x)
{
    struct node *temp, *p;

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
}

void reverse(struct node *head)
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
    // head = prev;
    // return head;

} /*End of reverseList()*/
