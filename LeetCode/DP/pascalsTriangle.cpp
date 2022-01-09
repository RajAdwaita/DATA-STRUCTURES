#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> pasc(numRows);
        // pasc[0].push_back(1);
        // if (numRows == 1)
        //     return pasc;

        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || (i == j))
                {
                    pasc[i].push_back(1);
                }
                else
                {
                    int x = pasc[i - 1][j - 1] + pasc[i - 1][j];
                    pasc[i].push_back(x);
                }
            }
        }
        return pasc;
    }
};

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }