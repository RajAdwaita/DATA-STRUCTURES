#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> v;
        if (n == 0)
        {
            v.push_back(0);
            return v;
        }
        v.push_back(0);

        for (int i = 1; i < n + 1; i++)
        {
            int cc = 0;
            int k = i;

            while (k > 0)
            {
                if (k % 2 == 1)
                    cc++;
                k /= 2;
            }
            v.push_back(cc);
        }
        return v;
    }
};

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }