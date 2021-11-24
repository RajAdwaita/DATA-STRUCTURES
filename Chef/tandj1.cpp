#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    int a, b, c, d, k, count;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c >> d >> k;
        int d1 = abs(a - c);
        int d2 = abs(b - d);
        count = d1 + d2;
        if (count <= k and count % 2 == 0 and k % 2 == 0)
        {
            cout << "YES" << endl;
        }
        else if (count <= k and count % 2 != 0 and k % 2 != 0)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}