#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    std::ios::sync_with_stdio(false);

    int t, n, lenn = 0;
    cin >> t;
    int end = 0;
    while (t--)
    {
        cin >> n;
        vector<int> arr;
        for (int i = 1; i <= n; i++)
            arr.push_back(i);

        int end = 0;
        int start = 0;
        if (n == 1 || n == 2)
        {
            cout << 1 << endl;
        }
        else
        {
            int start = 0, end = 0;
            int curr = 0;
            lenn = 1;
            int nums = 0;

            while (end <= n)
            {
                nums = arr[end] & arr[end + 1];
                if (nums >= 0)
                {
                    end++;
                    lenn++;
                }
                else
                {
                    start++;
                    end = start;
                    // nums = arr[start];
                    nums = 0;
                    lenn = 1;
                }
            }
        }
    }
    return 0;
}