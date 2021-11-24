#include <bits/stdc++.h>
using namespace std;

int calc_disp(int x)
{
    // int flag = 0;
    if (x % 3 == 0 || x % 10 == 3)
        return 1;
    else
        return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> nums;
        int n;
        int p = 1;
        cin >> n;
        // int t = calc_disp(n);
        for (int i = 1; i <= n; i++)
        {
            if (calc_disp(p) == 1)
            {
                p += 1;
            }
            else
            {
                p += 0;
            }
            // cout << p << endl;
            if (calc_disp(p) == 1)
            {
                p += 1;
            }
            nums.push_back(p);
            p += 1;
        }

        cout << nums[nums.size() - 1] << endl;
    }

    return 0;
}