#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int l, x;
        scanf("%d %d", &l, &x);

        char str[50];

        gets(str);
        int count = 0;
        int max = 0;
        int flag = 0;

        for (int j = 0; j < l; j++)
        {

            if (str[j] == '*')
            {
                count++;
            }
            else
            {
                max = count;
                if (max == x)
                {
                    printf("YES\n");
                    flag = 1;
                    break;
                }
                else
                {
                    count = 0;
                }
            }
        }
        if (flag == 0)
        {
            printf("NO");
        }
    }
    return 0;
}
