#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};
int c = 0;

struct node *createList(struct node *head);
void displayList(struct node *head);
struct node *insertInBeginning(struct node *head, int data);
void insertAtEnd(struct node *head, int data);
struct node *concat(struct node *head1, struct node *head2);

int main()
{
    struct node *head1 = NULL, *head2 = NULL;

    head1 = createList(head1);
    head2 = createList(head2);

    printf("First List is : ");
    displayList(head1);
    printf("second List is : ");
    displayList(head2);

    head1 = concat(head1, head2);

    printf("Concatenated   List is : ");
    displayList(head1);

    return 0;
}

struct node *createList(struct node *head)
{
    int i, n, data;
    if (c == 0)
    {
        printf("Enter the even elements:\n");
        c = 1;
    }
    else
        printf("Enter the odd elements: \n");
    c++;

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

struct node *concat(struct node *head1, struct node *head2)
{
    struct node *p;
    if (head1 == NULL)
    {
        head1 = head2;
        return head1;
    }

    if (head2 == NULL)
        return head1;
    p = head1;
    while (p->link != NULL)
        p = p->link;
    p->link = head2;
    return head1;
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
