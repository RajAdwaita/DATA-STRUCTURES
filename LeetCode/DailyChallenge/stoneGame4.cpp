#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool winnerSquareGame(int n)
    {
        // int copy = n;
        // while (n > 0)
        // {
        //     int x = sqrt(n);
        //     if (x * x == n)
        //         return false;
        //     n -= x * x;
        // }
        // return true;

        boolean[] arr = new boolean[n + 1];

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                if (!arr[i - j * j])
                {
                    arr[i] = true;
                    break;
                }
            }
        }

        return arr[n];
    }
};