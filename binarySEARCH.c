#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
int c = 0;
int bin_search(int a[], int n, int value);
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

    index = bin_search(a, n, value);
    if (index == -1)
        printf("%d not found in the array:\n", value);
    else
        printf("%d is found at index %d\n", value, index);

    return 0;
}

int bin_search(int a[], int n, int value)
{

    int lb = 0, ub = n - 1, mid;

    while (lb <= ub)
    {
        mid = (lb + ub) / 2;
        if (value == a[mid])
            return mid;
        else if (value > a[mid])
            lb = mid + 1;
        else if (value < a[mid])
            ub = mid - 1;
    }
    return -1;
}
