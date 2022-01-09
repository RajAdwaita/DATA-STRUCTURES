#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int tribonacci(int n)
    {
        int a = 0;
        int b = 1;
        int c = 1;
        int d = 0;
        for (int i = 0; i <= n - 3; i++)
        {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return d;
    }
};

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }