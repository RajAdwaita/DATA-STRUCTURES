#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfMatches(int n)
    {
        int cp = n;
        int match = 0;
        while (cp > 0)
        {
            if (cp % 2 == 0)
            {
                match += (cp / 2);
                cp = cp / 2;
            }
            else
            {
                match += ((cp - 1) / 2);
                cp = ((cp - 1) / 2);
            }
        }
        return match;
    }
};

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }