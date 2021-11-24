#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        double z = 0.0;

        if ((x + y) >= 6)
            cout << 0 << endl;
        else
        {
            z = (double)(6.0 - (x + y)) / 6.0;
            cout << z << endl;
        }
    }
    return 0;
}