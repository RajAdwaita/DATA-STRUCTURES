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
void SortByExchangingData(struct node *head);
struct node *SortByExchangingLinks(struct node *head);

int main()
{

    struct node *head1 = NULL, *head2 = NULL;

    printf("Create first list: \n");
    head1 = createList(head1);
    SortByExchangingData(head1);
    displayList(head1);

    printf("Create second list: \n");
    head2 = createList(head2);
    SortByExchangingData(head2);
    displayList(head2);

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

void SortByExchangingData(struct node *head)
{
    struct node *end, *p, *q;

    int temp;
    for (end = NULL; end != head->link; end = p)
    {
        for (p = head; p->link != end; p = p->link)
        {
            q = p->link;
            if (p->info > q->info)
            {
                temp = p->info;
                p->info = q->info;
                q->info = temp;
            }
        }
    }
}

struct node *SortByExchangingLinks(struct node *head)
{
    struct node *end, *p, *q, *r, *temp;

    for (end = NULL; end != head->link; end = p)
    {
        for (r = p = head; p->link != end; r = p, p = p->link)
        {
            q = p->link;
            if (p->info > q->info)
            {
                p->link = q->link;
                q->link = p;
                if (p != head)
                    r->link = q;
                else
                    head = q;

                temp = p;
                p = q;
                q = temp;
            }
        }
    }

    return head;
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
