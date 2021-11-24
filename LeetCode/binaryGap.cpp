#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int binaryGap(int n)
    {
        vector<int> bin;
        while (n > 0)
        {
            int x = n % 2;
            bin.insert(bin.begin(), x);
            n /= 2;
        }
        int max_dist = 0;

        for (int i = 0; i < bin.size(); i++)
        {

            int cc = 0;

            if (bin[i] == 1)
            {
                for (int j = i + 1; j < bin.size(); j++)
                {
                    if (bin[j] == 1)
                    {
                        cc = j - i;
                        break;
                    }
                }
                max_dist = max(max_dist, cc);
            }
        }
        return max_dist;
        // for (auto &i : bin)
        // {
        //     cout << i << "";
        // }
    }
};

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n = 10;

//     return 0;
// }