#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int main()
{
    int a[MAX], n, temp, minIndex;

    printf("Enter number of Elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d ", i + 1);
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
                minIndex = j;
        }
        if (i != minIndex)
        {
            temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }

    printf("Sorted Array : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");

    return 0;
}