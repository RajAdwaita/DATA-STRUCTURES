#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, x;
        int tot = 0;
        cin >> a >> b;
        if (a == b)
            tot = 0;
        else if (a < b)
        {
            x = a + 1;
            tot = ceil((b - x) / 2);
            tot += ceil((x - a) / 2);
        }
        else if (b < a)
        {
            x = b + 1;
            tot = ceil((b - x) / 2);
            tot += ceil((x - a) / 2);
        }

        cout << tot << endl;
    }

    return 0;
}