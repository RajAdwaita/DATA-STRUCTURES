#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        if (k % 2 == 0)
            cout << (k / 2) * 3 + (k / 2) * (-1) << endl;
        else
        {
            cout << ((k - 1) / 2) * 3 + ((k - 1) / 2) * (-1) + 3 << endl;
        }
    }

    return 0;
}