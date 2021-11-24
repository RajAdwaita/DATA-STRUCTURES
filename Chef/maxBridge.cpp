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
        int n, m;
        cin >> n >> m;

        // if (n == m)
        // {
        //     for (int i = 1; i < n; i++)
        //     {
        //         cout << i << " " << i + 1 << endl;
        //     }
        //     cout << n  << " " << 1 << endl;
        // }
        // else
        // {
        map<int, int> mp;
        for (int i = 1; i < n; i++)
        {
            // int x;
            // cin >> x;
            mp[i] = i + 1;
            cout << i << " " << i + 1 << endl;
            m = m - 1;
        }

        int next = 3;

        while (m > 0)
        {
            for (int i = 1; i < next; i++)
            {
                if (mp[i] < next)
                {
                    mp.insert(std::pair<int, int>(i, next));
                    cout << i << " " << next << endl;
                    m = m - 1;

                    if (m == 0)
                        break;
                }
            }
            next = next + 1;
            // }
        }
    }

    return 0;
}