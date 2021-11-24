#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, p, k;
        cin >> n >> p >> k;

        ll tot = 0;
        ll n1 = p % k;
        n1--;

        ll n2 = ((n - 1) / k) * k;
        n2 = n - 1 - n2;

        if (n1 > n2)
        {
            tot += (n2 + 1) * ((n - 1) / k + 1) + (n1 - n2) * ((n - 1) / k);
        }

        else
        {
            tot += ((n - 1) / k + 1) * (n1 + 1);
        }

        for (int i = n1 + 1; i <= n - 1; i += k)
        {
            tot++;
            if (i == p)
            {
                cout << tot << endl;
                goto end;
            }
        }

    end:;
    }

    return 0;
}