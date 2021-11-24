#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, m;

    scanf("%d%d", &n, &m);
    int arr[m];

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max = 0, min = 100;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    printf("%d", (max - min));

    return 0;
}