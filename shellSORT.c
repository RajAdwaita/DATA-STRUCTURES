#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int main()
{
    int a[MAX], temp, n, i, j, h;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the element %d ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("Enter max increment(odd val) : ");
    scanf("%d", &h);

    while (h >= 1)
    {
        for (i = h; i < n; i++)
        {
            temp = a[i];
            for (j = i - h; j >= 0 && a[j] > temp; j = j - h)
                a[j + h] = a[j];
            a[j + h] = temp;
        }
        h -= 2;
    }

    printf("The sorted List is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }

    return 0;
}