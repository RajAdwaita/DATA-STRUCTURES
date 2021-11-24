#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r1, r2, w1, w2, c1, c2;
        cin >> r1 >> w1 >> c1;
        cin >> r2 >> w2 >> c2;

        int tot1 = 0;
        int tot2 = 0;
        if (r1 > r2)
            tot1 += 1;
        else
            tot2 += 1;

        if (w1 > w2)
            tot1 += 1;
        else
            tot2 += 1;

        if (c1 > c2)
            tot1 += 1;
        else
            tot2 += 1;

        if (tot1 > tot2)
            cout << "A" << endl;
        else
            cout << "B" << endl;
    }
    return 0;
}