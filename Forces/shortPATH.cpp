#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        pair<int, int> a, b, f;
        int x, y;
        cin >> x >> y;
        a = make_pair(x, y);
        cin >> x >> y;
        b = make_pair(x, y);
        cin >> x >> y;
        f = make_pair(x, y);
        int dist = 0;
        dist = abs(a.first - b.first) + abs(a.second - b.second);
        // cout << dist << endl;

        if ((a.first == b.first && a.first == f.first && min(a.second, b.second) < f.second && f.second < max(a.second, b.second)) || (a.second == b.second && a.second == f.second && min(a.first, b.first) < f.first && f.first < max(a.first, b.first)))
        {
            dist += 2;
            //     cout << a.first << a.second << endl;
            //     cout << b.first << b.second << endl;
            //     cout << f.first << f.second << endl;
        }
        cout << dist << endl;
    }
    return 0;
}