#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int i;
int main()
{
    int a[MAX], n, temp, x;

    printf("Enter number of Elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d ", i + 1);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        printf("Pass %d\n", (i + 1));
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
            // printf("Sorted Array : \n");
            for (int i = 0; i < n; i++)
            {
                printf("%d  ", a[i]);
            }
            printf("\n");
        }
        printf("---------------------------------\n");
    }

    printf("----------------------\n");
    printf("----------------------\n");
    printf("Final sorted array: \n");

    for (int i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");

    return 0;
}