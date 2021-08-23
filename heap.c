#include <stdio.h>
#include <stdlib.h>
#define LARGE_VALUE 99999

void insert(int value, int a[], int *pn);
int deleteRoot(int a[], int *pn);
void restoreUp(int a[], int loc);
void restoreDown(int a[], int i, int size);
void display(int a[], int n);

int main()
{
    int a[50];
    int n = 0;
    int choice, value;

    a[0] = LARGE_VALUE;

    while (1)
    {
        printf("1.Insert\n");
        printf("2.Delete Root\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice\n");

        scanf("%d", &choice);

        if (choice == 4)
            break;

        switch (choice)
        {
        case 1:
            printf("Enter value to be inserted  : ");
            scanf("%d", &value);
            insert(value, a, &n);
            break;

        case 2:
            if (n == 0)
                printf("Heap is empty\n");
            else
            {
                value = deleteRoot(a, &n);
                printf("Maximum value is %d\n", value);
            }
            break;

        case 3:
            display(a, n);
            break;
        default:
            printf("Wrong Choice\n");
        }
    }
}

void insert(int value, int a[], int *pn)
{
    (*pn)++;
    a[*pn] = value;
    restoreUp(a, *pn);
}

void restoreUp(int a[], int i)
{
    int k = a[i];
    int iparent = i / 2;

    while (a[iparent] < k)
    {
        a[i] = a[iparent];
        i = iparent;
        iparent = i / 2;
    }
    a[i] = k;
}

int deleteRoot(int a[], int *pn)
{
    int maxValue = a[1];
    a[1] = a[*pn];
    (*pn)--;
    restoreDown(a, 1, *pn);
    return maxValue;
}

void restoreDown(int a[], int i, int n)
{
    int k = a[i];
    int lchild = 2 * i, rchild = lchild + 1;

    while (rchild <= n)
    {
        if (k >= a[lchild] && k >= a[rchild])
        {
            a[i] = k;
            return;
        }
        else if (a[lchild] > a[rchild])
        {
            a[i] = a[lchild];
            i = lchild;
        }
        else
        {
            a[i] = a[rchild];
            i = rchild;
        }

        lchild = 2 * i;
        rchild = lchild + 1;
    }

    if (lchild == n && k < a[lchild])
    {
        a[i] = a[lchild];
        i = lchild;
    }
    a[i] = k;
}

void display(int a[], int n)
{
    printf("Heap size = %d\n", n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
