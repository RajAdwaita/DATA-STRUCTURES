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
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int prod = 1;
        vector<int> submit;
        int count = (nums.begin(), nums.end(), 0);
        if (count > 1)
        {
            vector<int> final(nums.size());
            return final;
        }
        else if (count == 1)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == 0)
                    prod *= nums[i];
            }
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == 0)
                {
                    submit.push_back(prod);
                }
                else
                {
                    submit.push_back(0);
                }
            }
            return submit;
        }
        else if (count == 0)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                // if (nums[i] == 0)
                prod *= nums[i];
            }
            for (int i = 0; i < nums.size(); i++)
            {
                // if (nums[i] == 0)
                int term = prod / nums[i];
                submit.push_back(term);
            }
        }
        return submit;
    }
};