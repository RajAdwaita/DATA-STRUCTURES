#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void mergeSort(int a[], int low, int up);
void merge(int a[], int temp[], int low1, int up1, int low2, int up2);
void copy(int a[], int temp[], int low, int up);
int main()
{
    int i, n, a[MAX];

    printf("Enter number of Elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d ", i + 1);
        scanf("%d", &a[i]);
    }

    mergeSort(a, 0, n - 1);

    printf("The sorted list is : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

void mergeSort(int a[], int low, int up)
{
    int mid;
    int temp[MAX];

    if (low == up)
        return;

    mid = (low + up) / 2;

    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, up);

    merge(a, temp, low, mid, mid + 1, up);

    copy(a, temp, low, up);
}

void merge(int a[], int temp[], int low1, int up1, int low2, int up2)
{
    int i = low1;
    int j = low2;
    int k = low1;

    while ((i <= up1) && (j <= up2))
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

void copy(int a[], int temp[], int low, int up)
{
    for (int i = low; i <= up; i++)
    {
        a[i] = temp[i];
    }
}