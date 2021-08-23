#include <stdio.h>
#include <stdlib.h>

struct node

{
    int info;
    struct node *link;
};

struct node *createList(struct node *head);
void displayList(struct node *head);

struct node *insertInBeginning(struct node *head, int data);
void insertAtEnd(struct node *head, int data);
// void SortByExchangingData(struct node *head);
struct node *mergeSort(struct node *p);
struct node *divideList(struct node *p);
struct node *merge(struct node *p, struct node *q);

int main()
{

    struct node *head = NULL;

    head = createList(head);
    head = mergeSort(head);
    displayList(head);

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

struct node *mergeSort(struct node *head)
{

    struct node *head1, *head2, *headM;

    if (head == NULL || head->link == NULL) /*If list is empty or has one  element*/
        return head;
    head1 = head;
    head2 = divideList(head);
    head1 = mergeSort(head1);
    head2 = mergeSort(head2);
    headM = merge(head1, head2);
}

struct node *divideList(struct node *p)
{
    struct node *q, *head2;

    q = p->link->link;
    while (q != NULL && q->link != NULL)
    {
        p = p->link;
        q = q->link->link;
    }
    head2 = p->link;
    p->link = NULL;
    return head2;
}

struct node *merge(struct node *p1, struct node *p2)
{
    struct node *headM, *pM;

    if (p1->info <= p2->info)
    {
        headM = p1;
        p1 = p1->link;
    }
    else
    {
        headM = p2;
        p2 = p2->link;
    }
    pM = headM;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->info <= p2->info)
        {
            pM->link = p1;
            pM = pM->link;
            p1 = p1->link;
        }

        else
        {
            pM->link = p2;
            pM = pM->link;
            p2 = p2->link;
        }
    }

    if (p1 == NULL)
        pM->link = p2;
    else
        pM->link = p1;

    return headM;
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

    printf("Sorted List is : ");

    p = head;
    while (p != NULL)
    {
        printf("%d   ", p->info);
        p = p->link;
    }
    printf("\n");
}