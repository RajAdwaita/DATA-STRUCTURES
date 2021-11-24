#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        int tot = 0;
        for (int i = 0; i < jewels.length(); i++)
        {
            for (int j = 0; j < stones.length(); j++)
            {
                if (stones[j] == jewels[i])
                    tot++;
            }
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