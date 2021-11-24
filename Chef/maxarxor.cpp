#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int max1 = pow(2, n - 1);
        if (k > max1)
        {
            cout << (pow(2, n - 1)) * 2 * max1 << endl;
        }
        else
        {
            cout << pow(2, n - 1) * 2 * k << endl;
        }
    }

    return 0;
}