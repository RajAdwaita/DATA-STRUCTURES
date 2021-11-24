#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    int t, a, b, c;
    cin >> t;

    while (t--)
    {
        cin >> a >> b >> c;
        if (a == 7)
            cout << "YES" << endl;
        else if (b == 7)
            cout << "YES" << endl;
        else if (c == 7)
            cout << "YES" << endl;
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}