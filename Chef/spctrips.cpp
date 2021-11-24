#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int numtot = 0;
        for (int c = 1; c <= n / 2; c++)
        {
            for (int b = c; b <= n; b += c)
            {
                for (int a = c; a <= n; a += b)
                {
                    if (a % b == c && b % c == 0)
                        numtot++;
                }
            }
        }
        cout << numtot << endl;
    }
    return 0;
}