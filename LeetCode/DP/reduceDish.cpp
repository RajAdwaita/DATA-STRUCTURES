#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        int summ = 0;
        int n = satisfaction.size();
        int t = n - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            summ += satisfaction[i];

            if (summ < 0)
                break;
            t--;
        }
        t++;
        summ = 0;
        k = 0;
        for (int i = t; i < n; i++)
        {
            summ += ((k++) * satisfaction[i]);
        }
        return summ;
    }
};

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }