// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         ll n;

//         ll tot_sum = 0;
//         cin >> n;
//         ll a[n];
//         ll b[n];

//         for (ll i = 0; i < n; i++)
//         {
//             cin >> a[i];
//         }
//         for (ll i = 0; i < n - 1; i++)
//         {
//             if ((i % 2 == 0 && a[i] % 2 != 0) || (i % 2 != 0 && a[i] % 2 == 0))
//             {
//                 ll temp = a[i];
//                 a[i] = a[i + 1];
//                 a[i + 1] = temp;
//             }

//             // else if ()
//         }
//         int last = n - 1;
//         if ((last % 2 == 0 && a[last] % 2 != 0) || (last % 2 != 0 && a[last] % 2 == 0))
//         {
//             ll temp = a[last];
//             a[last] = a[last - 1];
//             a[last - 1] = temp;
//         }

//         for (ll i = 0; i < n; i++)
//         {
//             if ((i % 2 == 0 && a[i] % 2 == 0) || (i % 2 != 0 && a[i] % 2 != 0))
//             {
//                 tot_sum += 1;
//             }
//         }
//         // for (ll i = 0; i < n; i++)
//         // {
//         //     cout << a[i] << " ";
//         // }

//         // for (ll i = 0; i < n; i++)
//         // {
//         //     b[i] = (a[i] + (i + 1)) % 2;
//         // }

//         // cout << accumulate(b, b + n, 0) << endl;

//         cout << tot_sum << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;

        ll tot_sum = 0;
        cin >> n;
        ll a[n];
        ll b[n];
        ll sum1 = 0;

        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll odd1 = 0, odd2 = 0, even1 = 0, even2 = 0;
        for (ll i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0)
                even1++;
            else
                odd1++;
        }

        even2 = n / 2;
        odd2 = n / 2 + n % 2;

        ll main1 = even1 - odd2;
        ll main2 = odd1 - even2;
        if (main1 > 0)
        {
            sum1 = even1 - odd2;
        }
        else if (main2 > 0)
        {
            sum1 = odd1 - even2;
        }

        cout << (n - sum1) << endl;
    }
    return 0;
}