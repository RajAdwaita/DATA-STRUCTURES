class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int tot = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size(); i++)
        {
            tot += i;
        }
        return tot - accumulate(nums.begin(), nums.end(), 0);
    }
};