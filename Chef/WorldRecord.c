#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        float a = 0.0, b = 0.0, c = 0.0, d = 0.0;

        scanf("%f%f%f%f", &a, &b, &c, &d);
        float prd = 100 / (a * b * c * d);
        if (prd < 9.575)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}