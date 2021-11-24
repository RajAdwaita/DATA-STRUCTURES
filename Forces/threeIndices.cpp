#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        int flag = -1;
        for (int i = 0; i < n; i++)
            cin >>
                nums[i];
        for (int i = 1; i < n - 1; i++)
        {
            int i1 = i - 1;
            int j1 = i;
            int k1 = i + 1;

            if (nums[i1] < nums[j1] && nums[j1] > nums[k1])
            {
                flag = 1;
                cout << "YES" << endl;
                cout << i1 + 1 << " " << j1 + 1 << " " << k1 + 1 << endl;
                break;
            }
        }
        if (flag == -1)
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}