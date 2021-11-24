#include <bits/stdc++.h>
using namespace std;
// typedef long long int int;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

int main()
{
    std::ios::sync_with_stdio(false);

    int t;

    cin >> t;
    int n;
    while (t--)
    {
        int n;
        vector<pair<int, int>> b;

        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            b.push_back({x, i});
        }

        sort(b.begin(), b.end());

        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (b[i].first > k)
            {
                b[i].first = k;
                k++;
            }

            else if (b[i].first == k)
                b[i].first = k;
        }

        sort(b.begin(), b.end(), cmp);

        for (int i = 0; i < n; i++)
        {
            cout << b[i].first << " ";
        }
        cout << endl;
    }
    return 0;
}