#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {

        vector<int> final(nums.size());
        if (nums.size() == 1)
            return nums[0];
        final[0] = nums[0];
        final[1] = max(nums[1], nums[0]);
        for (int i = 2; i < nums.size(); i++)
        {
            final[i] = max(final[i - 1], final[i - 2] + nums[i]);
        }
        return final[final.size() - 1];
    }
};

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }