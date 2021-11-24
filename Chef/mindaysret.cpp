#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int ans = 0;
        if (n % k > 0)
            cout << (n / k) + 1 << endl;
        else
        {
            cout << n / k << endl;
        }
    }

    return 0;
}