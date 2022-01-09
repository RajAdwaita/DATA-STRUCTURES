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
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        vector<int> temp;
        vector<vector<int>> temp1;
        temp = arr;
        sort(temp.begin(), temp.end());

        int minn = INT_MAX;

        for (int i = 1; i < temp.size(); i++)
        {
            int x = abs(temp[i] - temp[i - 1]);
            minn = min(minn, x);
        }

        for (int i = 1; i < temp.size(); i++)
        {
            vector<int> v;
            int x = abs(temp[i] - temp[i - 1]);
            if (x == minn)
            {
                v.push_back(temp[i - 1]);
                v.push_back(temp[i]);
            }
            if (v.size() != 0)

                temp1.push_back(v);
            // minn = min(minn, x);
        }
        return temp1;
    }
};