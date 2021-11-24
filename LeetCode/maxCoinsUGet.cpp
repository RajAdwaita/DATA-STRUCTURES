#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        int tot = 0;
        int limit = piles.size() - (piles.size() / 3);

        sort(piles.begin(), piles.end(), greater<int>());
        for (int i = 1; i < limit; i += 2)
        {
            tot += piles[i];
        }

        return tot;
    }
};
// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }