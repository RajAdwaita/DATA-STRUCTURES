#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> targetIndices(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<int> tot;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
                // return
                tot.push_back(i);
        }
        if (tot.size() == 0)
            tot.push_back(0);
        return tot;
    }
};