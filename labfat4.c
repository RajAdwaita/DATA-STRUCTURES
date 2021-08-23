#include <stdio.h>
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int stack[n];
    for (int i = 0; i < n; i++)
    {

        scanf("%d", &stack[i]);
    }
    int max = -1;
    int q1[k];
    int q2[k];
    q1[0] = stack[0];
    for (int i = 1; i < k; i++)
    {
        q1[i] = stack[i] + q1[i - 1];
    }
    q2[k - 1] = 0;
    int t = n - 1;
    for (int i = k - 2; i >= 0; i--)
    {
        q2[i] = stack[t] + q2[i + 1];
        t -= 1;
    }
    for (int i = 0; i < k; i++)
    {
        int sum = q1[i] + q2[i];
        if (sum > max)
            max = sum;
    }
    printf("%d", max);
}