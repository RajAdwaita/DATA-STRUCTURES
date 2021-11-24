#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, d, h;
    cin >> t;
    while (t--)
    {
        cin >> n >> d >> h;
        vector<int> water(n);
        for (int i = 0; i < n; i++)
        {
            cin >> water[i];
        }
        int totalLevel = 0;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {

            int x = water[i];
            if (x != 0)
                totalLevel += x;
            if (totalLevel < d && i != 0)
                totalLevel = 0;
            else if (x == 0)
            {
                totalLevel -= d;
            }

            if (totalLevel > h)
            {
                cout << "YES" << endl;
                flag = -1;
                break;
            }
        }
        if (flag == 0)
            cout << "NO" << endl;
        // totalLevel = accumulate(water.begin(), water.end(), 0);
        // int countZero = count(water.begin(), water.end(), 0);

        // totalLevel = totalLevel - (d * countZero);

        // if(totalLevel>)
    }
    return 0;
}