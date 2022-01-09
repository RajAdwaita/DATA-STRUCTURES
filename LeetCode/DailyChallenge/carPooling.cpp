#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<int> seats(1001, 0);
        for (auto &trip : trips)
        {
            seats[trip[1]] += trip[0];
            seats[trip[2]] -= trip[0];
        }
        int cur = 0;
        for (int seat : seats)
        {
            cur += seat;
            if (cur > capacity)
            {
                return false;
            }
        }
        return true;
    }
};