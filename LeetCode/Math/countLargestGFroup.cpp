// Given an integer n.Each number from 1 to n is grouped according to the sum of its digits.

//     Return how many groups have the largest size.

class Solution
{
public:
    int countLargestGroup(int n)
    {
        int ans = 0;
        int max = 0;
        vector<int> count(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            int sum = 0;
            while (i)
            {
                sum += i % 10;
                i /= 10;
            }
            count[sum]++;
            max = max > count[sum] ? max : count[sum];
        }
        for (int i = 1; i <= n; i++)
        {
            if (count[i] == max)
                ans++;
        }
        return ans;
    }
};