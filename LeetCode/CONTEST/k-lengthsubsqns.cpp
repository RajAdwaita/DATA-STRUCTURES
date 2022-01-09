#include <bits/stdc++.h>
using namespace std;

// You are given an integer array nums and an integer k.You want to find a subsequence of nums of length k that has the largest sum.

//     Return any such subsequence as an integer array of length k.

//     A subsequence is an array that can be derived from another array by deleting some or
//     no elements without changing the order of the remaining elements.

class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        vector<int> ans1;
        vector<int> ans2(nums.size(), -999);
        unordered_map<int, int> mp;
        vector<int> ans;

        ans1 = nums;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]] = i;
        }

        sort(nums.begin(), nums.end());

        for (int i = nums.size() - k; i < nums.size(); i++)
            ans.push_back(nums[i]);

        for (int i = 0; i < ans.size(); i++)
        {
            // cout << ans[i] << " ";
            ans2[mp[ans[i]]] = ans[i];
        }
        vector<int> ans3;
        for (int i = 0; i < ans2.size(); i++)
        {
            if (ans2[i] != -999)
                ans3.push_back(ans2[i]);
        }

        return ans3;
    }
};
// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }