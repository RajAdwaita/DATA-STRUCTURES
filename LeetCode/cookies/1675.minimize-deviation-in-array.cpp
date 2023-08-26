/*
 * @lc app=leetcode id=1675 lang=cpp
 *
 * [1675] Minimize Deviation in Array
 */

// @lc code=start
class Solution
{
public:
    priority_queue<int> pq;
    int minimumDeviation(vector<int> &nums)
    {

        int n = nums.size();
        int a = INT_MAX;
        int b = INT_MAX;

        for (auto &i : nums)
        {
            if (i % 2 == 1)
                i *= 2;
            pq.push(i);
            a = min(a, i);
        }

        while (pq.top() % 2 == 0)
        {
            b = min(b, pq.top() - a);
            a = min(a, pq.top() / 2);
            pq.push(pq.top() / 2);
            pq.pop();
        }

        return min(pq.top() - a, b);
    }
};
// @lc code=end
