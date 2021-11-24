#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// ll calc_disp(ll L, ll R)
// {
//     ll LXR = L % R;

//     ll msbPos = 0;
//     while (LXR)
//     {
//         msbPos++;
//         LXR >>= 1;
//     }

//     ll maxX = 0;
//     ll two = 1;
//     while (msbPos--)
//     {
//         maxX += two;
//         two <<= 1;
//     }
//     return maxX;
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        ll a, b;
        cin >> l >> r;
        // cout << calc_disp(l, r) << endl;
        if (l > r / 2)
            cout << r % l << endl;
        else
        {
            cout << (r) % ((r / 2) + 1) << endl;
        }
    }
    return 0;
}