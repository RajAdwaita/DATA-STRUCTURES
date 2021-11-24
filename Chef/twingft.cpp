#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k;

    cin >> t;

    int x{0};
    while (t--)
    {

        int tot1{0}, tot2{0}, c1{0}, c2{0};

        cin >> n >> k;
        int v[n];
        for (int i = 0; i < n; i++)
        {
            cin >>
                v[i];
        }
        // cout << v << endl;
        // int l = v.size();

        sort(v, v + n, greater<int>());
        int i = 0;
        if (n < 3)
        {
            tot1 = v[0];
            tot2 = v[1];
        }
        else
        {
            for (i = 0; i < n - 2; i++)
            {
                if (i % 2 == 0 && c1 != k)
                {
                    tot1 += v[i];
                    c1++;
                }
                if (i % 2 != 0)
                {
                    tot2 += v[i];
                    c2++;
                }
                if (c2 == k)
                    break;
            }
            // if (i != n - 1)
            tot2 += v[n - 1] + v[n - 2];
        }

        cout << max(tot1, tot2) << endl;

        // else if (n > 2)
        // {
        //     for (int i = 0; i < n - 2; i++)
        //     {
        //         if (i % 2 == 0)
        //         {
        //             v1.push_back(v[i]);
        //         }
        //         else
        //             v2.push_back(v[i]);
        //     }
        //     tot1 = accumulate(v1.begin(), v1.end(), 0);
        //     tot2 = accumulate(v2.begin(), v2.end(), 0);
        //     tot2 += v[n - 1] + v[n - 2];
        // }

        // cout << max(tot1, tot2) << endl;
    }

    return 0;
}