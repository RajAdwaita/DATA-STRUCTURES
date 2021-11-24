#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    int t, a, b;

    cin >> t;
    while (t--)
    {
        cin >> a >> b;

        if (a > 0 && b > 0)
            cout << "Solution" << endl;
        else if (b == 0)
            cout << "Solid" << endl;

        else if (a == 0)
            cout << "Liquid" << endl;
    }
    return 0;
}