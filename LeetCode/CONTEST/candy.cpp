class Solution
{
public:
    int minimumCost(vector<int> &cost)
    {
        int n = cost.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return cost[0];
        if (n == 2)
            return (cost[0] + cost[1]);

        sort(cost.begin(), cost.end());

        int sum = 0;
        int k = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            k++;
            if (k % 3 != 0)
            {
                sum += cost[i];
                // k++;
            }
            // k++;
            // if (k == 2)
            // {
            //     k = 0;
            // }
        }

        return sum;
    }
};