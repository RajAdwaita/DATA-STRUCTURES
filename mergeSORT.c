#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void mergeSort(int a[], int n);
void sortPass(int a[], int temp[], int soze, int n);
void merge(int a[], int temp[], int low1, int up1, int low2, int up2);
void copy(int a[], int temp[], int n);
int main()
{
    int a[MAX], n;
    printf("Enter number of Elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d ", i + 1);
        scanf("%d", &a[i]);
    }
    mergeSort(a, n);

    printf("Sorted list is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

void mergeSort(int a[], int n)
{
    int size = 1;
    int temp[MAX];

    while (size <= n - 1)
    {
        sortPass(a, temp, size, n);
        size *= 2;
    }
}

void sortPass(int a[], int temp[], int size, int n)
{
    int i, low1, up1, low2, up2;

    low1 = 0;

    while (low1 + size <= n - 1)
    {

        up1 = low1 + size - 1;
        low2 = low1 + size;
        up2 = low2 + size - 1;

        if (up2 >= n)
            up2 = n - 1;

        merge(a, temp, low1, up1, low2, up2);

        low1 = up2 + 1;
    }

    for (i = low1; i <= n - 1; i++)
        temp[i] = a[i];

    copy(a, temp, n);
}

void merge(int a[], int temp[], int low1, int up1, int low2, int up2)
{
    int i = low1;
    int j = low2;
    int k = low1;

    while (i <= up1 && j <= up2)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= up1)
        temp[k++] = a[i++];

    while (j <= up2)
        temp[k++] = a[j++];
}

void copy(int a[], int temp[], int n)
{
    for (int i = 0; i < n; i++)
        a[i] = temp[i];
}