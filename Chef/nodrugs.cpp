#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, l;
        cin >> n >> k >> l;

        vector<int> speeds;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            speeds.push_back(x);
        }

        int fr = speeds[n - 1];

        if (k > 0)
        {
            int max_pos = (l - 1) * k;
            int tot_speed = fr + max_pos;
            speeds[n - 1] = tot_speed;
        }

        int max_speed = *max_element(speeds.begin(), speeds.end());
        if (max_speed == speeds[n - 1] && count(speeds.begin(), speeds.end(), max_speed) == 1)
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }

    return 0;
}