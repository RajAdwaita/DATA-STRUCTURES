#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (k == 1)
            cout << (n - 1) * 2 << endl;

        else
        {
            cout << (n - k + 1) * 2 << endl;
        }
    }
    return 0;
}