#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
int search(int a[], int n, int value);
int main()
{
    int n, value, a[SIZE], index;

    printf("Enter number of Elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("Enter element to be searched for: ");
    scanf("%d", &value);

    index = search(a, n, value);
    if (index == -1)
        printf("%d not found in the array:\n", value);
    else
        printf("%d is found at index %d\n", value, index);

    return 0;
}

int search(int a[], int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == value)
            return i;
    }
    return -1;
}