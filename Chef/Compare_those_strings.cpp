#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int ans = 0;
        bool temp;
        temp = a[n - 1] < b[n - 1];
        if (temp)
        {
            ans++;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] < b[i])
            {
                ans++;
                temp = true;
            }
            else if (a[i] > b[i])
            {
                temp = false;
            }
            else
            {
                if (temp)
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}