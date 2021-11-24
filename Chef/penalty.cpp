#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> pens(10);

        for (int i = 0; i < 10; i++)
        {
            cin >> pens[i];
        }
        int t1 = 0, t2 = 0;

        for (int i = 0; i < 10; i++)
        {
            if (i % 2 == 0 && pens[i] == 1)
                t1++;

            else if (i % 2 != 0 && pens[i] == 1)
                t2++;
        }

        if (t1 > t2)
            cout << 1 << endl;
        else if (t2 > t1)
            cout << 2 << endl;

        else
            cout << 0 << endl;
    }
    return 0;
}