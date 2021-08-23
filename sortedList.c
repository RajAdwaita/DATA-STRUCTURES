#include <stdio.h>
#include <stdlib.h>

struct node

{
    int info;
    struct node *link;
};

void displayList(struct node *head);
void search(struct node *head, int x);
struct node *insertInOrder(struct node *head, int data);

int main()
{

    struct node *head = NULL;
    int choice, data;

    while (1)
    {

        printf("\n");
        printf("1.Display list:\n ");

        printf("2.Insert a new Node:\n ");
        printf("3.Search:\n ");

        printf("4.Exit:\n\n ");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4)
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
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            head = insertInOrder(head, data);
            break;
        }
        case 3:
        {
            printf("Enter the element to be searched: ");
            scanf("%d", &data);
            search(head, data);
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

struct node *insertInOrder(struct node *head, int data)
{
    struct node *p, *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;

    if (head == NULL || data < head->info)
    {
        temp->link = head;
        head = temp;
        return head;
    }

    p = head;
    while (p->link != NULL && p->link->info <= data)
    {
        p = p->link;
    }
    temp->link = p->link;
    p->link = temp;
    // temp->link = NULL;
    return head;
}

void search(struct node *head, int x)
{
    struct node *p;
    int position;

    if (head == NULL)
    {
        printf("List is empty:\n");
        return;
    }

    p = head;
    position = 1;
    while (p != NULL && p->info <= x)
    {
        if (p->info == x)
            break;

        position++;
        p = p->link;
    }

    if (p == NULL || p->info != x)
        printf("%d not found in list\n", x);
    else
        printf("%d is at index %d\n", x, position - 1);
}
