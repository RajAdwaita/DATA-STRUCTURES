#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    std::ios::sync_with_stdio(false);

    ll t;
    cin >> t;
    while (t--)
    {
        ll maxx, minn;

        ll x, y;
        cin >> x >> y;
        cout << 2 * x << " ";

        cout << x * y * (x * y - 1) << endl;
    }
    return 0;
}
