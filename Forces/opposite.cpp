#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << "HEmlo" << endl;

    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int tot_points = 0;
        int d = 0;
        tot_points = 2 * abs(a - b);
        if (a > tot_points || b > tot_points || c > tot_points)
        {
            d = -1;
        }
        else
        {
            d = c + tot_points / 2;
            if (d > tot_points)
                d = c - tot_points / 2;
        }
        cout << d << endl;
    }

    return 0;
}