#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;

} *start = NULL;

void radixSort();
int digitsInLargest();
int digit(int number, int k);

int main()
{
    struct node *temp, *p;
    int n, item;

    printf("Enter number of Elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d ", i + 1);
        scanf("%d", &item);

        temp = (struct node *)malloc(sizeof(struct node));
        temp->info = item;
        temp->link = NULL;

        if (start == NULL)
            start = temp;
        else
        {
            p = start;
            while (p->link != NULL)
                p = p->link;
            p->link = temp;
        }
    }

    radixSort();

    printf("Sorted list is :\n");

    p = start;
    while (p != NULL)
    {
        printf("%d  ", p->info);
        p = p->link;
    }

    printf("\n");

    return 0;
}

void radixSort()
{
    int dig, leastSigPos, mostSigPos;
    struct node *p, *rear[10], *front[10];

    leastSigPos = 1;
    mostSigPos = digitsInLargest();

    for (int k = leastSigPos; k <= mostSigPos; k++)
    {
        for (int i = 0; i <= 9; i++)
        {
            rear[i] = NULL;
            front[i] = NULL;
        }

        for (p = start; p != NULL; p = p->link)
        {
            dig = digit(p->info, k);

            if (front[dig] == NULL)
                front[dig] = p;
            else
                rear[dig]->link = p;
            rear[dig] = p;
        }

        int i = 0;

        while (front[i] == NULL)
            i++;
        start = front[i];

        while (i <= 8)
        {
            if (rear[i + 1] != NULL)
                rear[i]->link = front[i + 1];
            else
                rear[i + 1] = rear[i];
            i++;
        }

        rear[9]->link = NULL;
    }
}

int digitsInLargest()
{
    struct node *p = start;

    int large = 0, ndigits = 0;

    while (p != NULL)
    {
        if (p->info > large)
            large = p->info;
        p = p->link;
    }

    while (large != 0)
    {
        ndigits++;
        large /= 10;
    }
    return ndigits;
}

int digit(int n, int k)
{
    int d;
    for (int i = 0; i < k; i++)
    {
        d = n % 10;
        n /= 10;
    }
    return d;
}