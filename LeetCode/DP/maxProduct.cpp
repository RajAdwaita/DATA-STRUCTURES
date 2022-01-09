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
    int maxProduct(vector<int> &nums)
    {
        int res = *max_element(nums.begin(), nums.end());
        int maxx = 1, minn = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            int t = maxx * nums[i];
            maxx = max(maxx * nums[i], max(minn * nums[i], nums[i]));
            minn = min(t, min(minn * nums[i], nums[i]));
            res = max(res, maxx);
        }
        return res;
    }
};