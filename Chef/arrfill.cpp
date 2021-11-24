// #include <bits/stdc++.h>
// using namespace std;

// ll main()
// {
//     ll t;
//     cin >> t;
//     while (t--)

//     {
//         ll x, y, m, n;
//         cin >> n >> m;
//         vector<ll> nums(35000);
//         vector<pair<ll, ll>> store;
//         for (ll i = 0; i < m; i++)
//         {
//             cin >> x >> y;
//             store.push_back(make_pair(x, y));
//         }
//         sort(store.begin(), store.end());
//         for (ll i = store.size() - 1; i >= 0; i--)
//         {
//             for (ll j = 1; j <= n; j++)
//             {
//                 if (j % store[i].second != 0 && nums[j - 1] == 0)
//                 {
//                     nums[j - 1] = store[i].first;
//                 }
//             }
//         }
//         cout << accumulate(nums.begin(), nums.end(), 0) << endl;
//     }
//     // for (auto i : nums)
//     // {
//     //     cout << i << " ";
//     // }
//     // cout << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    int t;
    cin >> t;
    while (t--)

    {
        ll x, y, m, n;
        cin >> n >> m;
        // vector<ll> nums(35000);
        vector<pair<int, int>> store;
        for (ll i = 0; i < m; i++)
        {
            cin >> x >> y;
            store.push_back(make_pair(x, y));
        }
        sort(store.begin(), store.end(), greater<pair<int, int>>());

        ll lcm = 1;
        ll rem = n;
        ll tot = 0;
        for (int i = 0; i < m && rem > 0; i++)
        {
            ll num1 = store[i].first;
            ll num2 = store[i].second;

            lcm = lcm * num2 / __gcd(lcm, num2);
            tot += (rem - n / lcm) * num1;
            rem = n / lcm;
        }

        cout << tot << endl;
    }
    // for (auto i : nums)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    return 0;
}