#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> temp;
        temp = heights;
        int count = 0;
        sort(temp.begin(), temp.end());
        for (int i = 0; i < heights.size(); i++)
        {
            if (temp[i] != heights[i])
            {
                count++;
            }
        }
        return count;
    }
};
// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }