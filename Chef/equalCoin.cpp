#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    std::ios::sync_with_stdio(false);
    ll t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        ll at = a * 1;
        ll bt = b * 2;
        ll tot = at + bt;
        if (a == 0 && b == 0)
            cout << "NO" << endl;

        else if (a % 2 != 0)
            cout << "NO" << endl;
        else if (a % 2 == 0 && b % 2 == 0)
            cout << "YES" << endl;
        else if (a > 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}