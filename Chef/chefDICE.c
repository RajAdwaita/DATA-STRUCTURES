// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     int n, d;

//     scanf("%d", &n);

//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &d);
//         int a = 0, b = 0, c = 0;
//         int tot = 0;

//         a = d / 4;
//         b = d % 4;
//         if (b == 1)
//             c = 20;
//         else if (b == 2)
//             c = 36;

//         else if (b == 3)
//             c = 51;
//         // else if (b == 0)
//         //     c = 60;
//         tot += c;

//         // if(b==0)
//         // {
//         //     tot += 36 * (a - 1);
//         //     tot+=36

//         // }
//         if (a >= 1)
//         {
//             tot += 44 * (a - 1);
//             tot += (15 * (4 - b)) + (11 * (b));
//         }

//         // tot = 44 * a + c;
//         printf("%d\n", tot);
//     }
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int nn, d;
    long long n;

    scanf("%d", &nn);

    for (int i = 0; i < nn; i++)
    {
        scanf("%d", &n);
        int a = 0, b = 0, c = 0;
        long long tot = 0;
        tot = (n / 4) * 44;
        int rem = n % 4;
        if (n >= 4)
        {
            if (rem == 0)
            {
                tot += 16;
            }
            if (rem == 1)
            {
                tot += 32;
            }
            if (rem == 2)
            {
                tot += 44;
            }
            if (rem == 3)
            {
                tot += 55;
            }

            printf("%d", tot);
        }

        else
        {
            int res;
            if (rem == 1)
            {
                res = 20;
            }

            if (rem == 2)
            {
                res = 36;
            }
            if (rem == 3)
            {
                res = 51;
            }

            printf("%d", res);
        }
    }
    return 0;
}