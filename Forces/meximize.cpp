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
        vector<int> a(n);
        vector<int> b;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++)
        {
            if (i == 0 || a[i] != a[i - 1])
            {
                b.emplace_back(a[i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && a[i] == a[i - 1])
            {
                b.emplace_back(a[i]);
            }
        }

        for (auto i : b)
        {
            cout << i << " ";
        }

        cout << endl;
    }
    return 0;
}