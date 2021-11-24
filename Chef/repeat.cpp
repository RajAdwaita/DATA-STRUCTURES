#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        // vector<ll> arr;
        ll n, s, k;
        cin >> n >> k >> s;

        ll odd_sum = (n * n);
        ll need = s - odd_sum;
        ll var = 0;
        var = need / (k - 1);
        cout << var << endl;
    }
    return 0;
}