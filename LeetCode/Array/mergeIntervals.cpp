#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        vector<vector<int>> res;
        if (intervals.size() == 0)
            return res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= res.back()[1])
            {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     vector<vector<int>> v = {{1, 2}, {8, 9}, {2, 3}, {4, 5}};
//     sort(v.begin(), v.end());
//     for (auto &i : v)
//     {
//         cout << i[0] << " " << i[1] << " " << endl;
//     }

//     return 0;
// }