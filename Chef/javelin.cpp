#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, m, x;
    cin >> t;
    while (t--)
    {
        int selected = 0;
        int min_parti = 0;
        cin >> n >> m >> x;
        vector<pair<int, int>> dist;
        vector<pair<int, int>> reserve;
        vector<int> final;
        int inp = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> inp;
            dist.push_back({inp, i + 1});
        }

        for (int i = 0; i < n; i++)
        {
            if (dist[i].first >= m)
            {
                selected++;
                final.push_back(i + 1);
            }
            else
            {
                reserve.push_back({dist[i].first, dist[i].second});
            }
        }

        if (selected >= x)
        {
            sort(final.begin(), final.end());
            cout << selected << " ";
            for (int i = 0; i < final.size(); i++)
            {
                cout << final[i] << " ";
            }
            cout << endl;
        }
        else
        {
            int need = x - selected;
            sort(reserve.rbegin(), reserve.rend());

            for (int i = 0; i < need; i++)
            {
                final.push_back(reserve[i].second);
                selected++;
            }
            sort(final.begin(), final.end());
            cout << selected << " ";
            for (int i = 0; i < final.size(); i++)
            {
                cout << final[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
