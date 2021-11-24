#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    int t;
    cin >> t;
    ll n, a, num, tot;
    while (t--)
    {
        cin >> n >> a;

        if (n < 4)
        {
            cout << a << endl;
        }
        else
        {
            num = floor(sqrt(n));
            tot = num * a;
            cout << tot << endl;
        }
    }
    return 0;
}