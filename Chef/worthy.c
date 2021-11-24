#include <stdio.h>
#include <stdlib.h>
int main()
{
    int nn;
    scanf("%d", &nn);
    for (int i = 1; i <= nn; i++)
    {
        int m, n, x;
        scanf("%d%d%d", &m, &n, &x);
        int arr[n][m];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         printf("%d  ", arr[i][j]);
        //     }
        // }

        return 0;
    }
}