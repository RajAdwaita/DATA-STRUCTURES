#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    int a, b, c;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        if (a <= b && a <= c)
        {
            cout << b + c << endl;
        }
        else if (b <= a && b <= c)
        {
            cout << a + c << endl;
        }
        else if (c <= b && c <= a)
        {
            cout << b + a << endl;
        }
    }
    return 0;
}