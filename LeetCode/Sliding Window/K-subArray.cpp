#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        int i = 0, j = 0;
        int n = arr.size();
        int ans = 0;
        int s = 0;
        while (j < n)
        {
            ans += arr[j];

            if (j - i + 1 < k)
            {
                j++;
                continue;
            }
            else if (j - i + 1 == k)
            {
                int avg = ans / k;
                if (avg >= threshold)
                    s++;
                ans -= arr[i];
                j++;
                i++;
            }

            return s;
        }
    }
};

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }