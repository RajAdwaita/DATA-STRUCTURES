#include <stdio.h>
#include <stdlib.h>
struct server
{
    int uvote;
    int dvote;
};
int main()
{

    struct server s1;
    struct server s2;

    int n, p;
    scanf("%d", &n);
    while (n--)
    {
        s1.uvote = s1.dvote = 0;

        scanf("%d", &p);
        int arr[p];
        for (int i = 0; i < p; i++)
        {
            scanf("%d", &arr[i]);
        }

        for (int i = 0; i < p; i++)

        {

            if (arr[i] == 1)
            {
                // if (s1.uvote == s2.uvote == 0)
                // {
                //     s1.uvote += 1;
                // }
                // else
                // {
                //     s1.uvote += 1;
                // }
                s1.uvote += 1;
            }
            else if (arr[i] == 2)
            {
                // if (s1.dvote == s2.dvote == 0)
                // {
                s1.dvote += 1;
                // }
            }
            else if (arr[i] == 3)
            {
                if (s1.uvote >= s1.dvote)
                {
                    s1.uvote += 1;
                }
                else
                {
                    s1.dvote += 1;
                }
            }
        }

        printf("%d\n", s1.uvote);
        // printf("%d\n", s1.dvote);
    }

    return 0;
}