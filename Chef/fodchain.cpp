#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int e, k;
        int count = 0;
        cin >> e >> k;
        if (e > 0)
            count = 1;

        if (e < k)
            cout << count << endl;
        else
        {
            cout << count + (int)(log(e / k) / log(k)) + 1 << endl;
        }
        // else if (e % k != 0)
        // {
        //     cout << floor(e / k) + 1 << endl;
        // }
        // else if (e % k == 0)
        //     cout << floor(e / k) - 1 << endl;
        // cin >> e >> k;
        // cout << e << k << endl;
    }
    return 0;
}