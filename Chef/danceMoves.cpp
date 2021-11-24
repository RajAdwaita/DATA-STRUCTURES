#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    int x, y;
    while (t--)
    {
        cin >> x >> y;
        if (y > x)
        {
            int tot = abs(y - x);
            if (tot % 2 == 0)
            {
                cout << ceil(tot / 2) << endl;
            }
            else
            {
                cout << ((tot + 1) / 2) + 1 << endl;
            }
        }
        else
        {
            cout << abs(x - y) << endl;
        }
    }

    return 0;
}