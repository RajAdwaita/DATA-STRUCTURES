#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int xa, ya, xb, xc, yb, yc;
        cin >> xa >> ya;
        cin >> xb >> yb;
        cin >> xc >> yc;
        // xa = abs(xa);
        // xb = abs(xb);
        // xc = abs(xc);
        // ya = abs(ya);
        // yb = abs(yb);
        // yc = abs(yc);

        // cout << ya << " " << yb << " " << yc << endl;
        int flag = -1;
        if (ya == yb && yb == yc)
        {
            if (xa >= xb && xb >= xc)
                flag = 1;

            else if (xc >= xb && xb >= xa)
                flag = 1;
            // cout << "All same" << endl;
        }
        else if (xa == xb && xb == xc)
        {
            if (ya >= yb && yb >= yc)
                flag = 1;
            else if (yc >= yb && yb >= ya)
                flag = 1;
            // cout << "All same" << endl;
        }
        else if (ya == yb && xb == xc)
        {
            flag = 1;
        }

        else if (xa == xb && yb == yc)
        {
            flag = 1;
        }

        if (flag == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}