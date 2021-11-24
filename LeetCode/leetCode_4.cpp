#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        int n = boxTypes.size();
        int m = boxTypes[0].size();
        vector<vector<int>> dp(n, vector<int>(truckSize + 1, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= truckSize; j++)
            {
                if (j < boxTypes[i][0])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - boxTypes[i][0]] + boxTypes[i][1]);
                }
            }
        }
        return dp[n - 1][truckSize];
    }
};