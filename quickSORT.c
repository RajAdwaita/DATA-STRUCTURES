#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void quickSort(int a[], int low, int up);
int partition(int a[], int low, int up);
int main()
{

    int a[MAX], n;

    printf("enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter elements %d ", i + 1);
        scanf("%d", &a[i]);
    }

    quickSort(a, 0, n - 1);

    printf("sorted list is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");

    return 0;
}

void quickSort(int a[], int low, int up)
{
    int p;
    if (low >= up)
    {
        return;
    }
    p = partition(a, low, up);
    quickSort(a, low, p - 1);
    quickSort(a, p + 1, up);
}

int partition(int a[], int low, int up)
{
    int temp, i, j, pivot;

    pivot = a[low];

    i = low + 1;
    j = up;

    while (i <= j)
    {
        while (a[i] < pivot && i < up)
            i++;

        while (a[j] > pivot)
            j--;

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }

        else
            break;
    }

    a[low] = a[j];
    a[j] = pivot;

    return j;
}