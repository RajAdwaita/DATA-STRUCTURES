#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    int t, x, y, a, b, k;
    cin >> t;
    while (t--)
    {
        cin >> x >> y >> a >> b >> k;
        int petrol = a * k;
        int diesel = b * k;

        x += petrol;
        y += diesel;

        if (x == y)
            cout << "SAME PRICE" << endl;
        else if (x > y)
            cout << "DIESEL" << endl;
        else
            cout << "PETROL" << endl;
    }

    return 0;
}