#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums;
        vector<int> nums1;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        sort(nums.begin(), nums.end());
        int cc = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0 && cc <= k)
            {
                nums[i] *= -1;
            }
            else
            {
                break;
            }

            cc++;
        }

        ll sum1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                sum1 += nums[i];
            }
            // else
            // {
            //     break;
            // }
        }

        cout << sum1 << endl;
        // int min = *min_element(nums.begin(), nums.end());
        // int max = *max_element(nums.begin(), nums.end());

        // nums1 = nums;
    }
    return 0;
}