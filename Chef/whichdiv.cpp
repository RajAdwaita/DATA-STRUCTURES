#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        if (x < 1600)
            cout << 3 << endl;
        else if (x >= 2000)
            cout << 1 << endl;
        else if (x >= 1600 && x < 2000)
            cout << 2 << endl;
    }

    return 0;
}