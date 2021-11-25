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
    void moveZeroes(vector<int> &nums)
    {
        vector<int> temp;
        int cc = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                // nums.erase(nums.begin() + i);
                cc++;
                // nums.push_back(0);
            }
            else
            {
                temp.push_back(nums[i]);
            }
        }
        for (int i = 0; i < cc; i++)
        {
            temp.push_back(0);
        }

        nums = temp;
    }
};