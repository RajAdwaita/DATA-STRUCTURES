// #include <bits/stdc++.h>
// using namespace std;

// vector<int> isHill(vector<int> &v)
// {
//     vector<int> ans;
//     int c = v.size() / 2;
//     vector<int> left;
//     vector<int> right;
//     for (int i = 0; i < c; i++)
//     {
//         left.push_back(v[i]);
//     }
//     sort(left.begin(), left.end());
//     for (int i = c; i < v.size(); i++)
//     {
//         right.push_back(v[i]);
//     }
//     sort(right.begin(), right.end(), greater<int>());

//     for (int i = 0; i < left.size(); i++)
//     {
//         ans.push_back(left[i]);
//     }
//     for (int i = 0; i < right.size(); i++)
//     {
//         ans.push_back(right[i]);
//     }

//     return ans;
// }

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int flag = 1;

//         vector<int> final;
//         int n;
//         vector<int> a;
//         cin >> n;
//         vector<int> a1;
//         for (int i = 0; i < n; i++)
//         {
//             int x;
//             cin >> x;
//             a.push_back(x);
//             a1.push_back(x);
//         }
//         int maxEle = *max_element(a.begin(), a.end());
//         if (count(a.begin(), a.end(), maxEle) > 1)
//         {
//             // final.push_back(-1);
//             cout << "-1" << endl;
//             flag = -1;
//             // break;
//             continue;
//         }
//         vector<int> freq;
//         for (int i = 0; i < n; i++)
//         {
//             int cc = count(a.begin(), a.end(), a[i]);
//             // freq.push_back(cc);
//             if (cc > 2)
//             {
//                 flag = -1;
//                 cout << "-1" << endl;
//                 // final.push_back(-1);
//                 // break;
//                 continue;
//             }
//         }
//         if (flag == 1)
//         {
//             // int middle = n / 2;
//             final = isHill(a);

//             for (int i = 0; i < final.size(); i++)
//             {
//                 cout << final[i] << " ";
//             }
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        map<ll, ll> m;
        int flag = 1;
        vector<ll> v, v1;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            m[x]++;
        }

        for (auto x : m)
        {
            if (x.second > 2)
            {
                flag = -1;
                break;
            }
            v.push_back(x.first);
        }

        sort(v.begin(), v.end());
        if (flag == -1 || m[v[v.size() - 1]] == 2)
        {
            cout << "-1" << endl;
            // continue;
            // break;
        }
        else
        {
            for (int i = 0; i < v.size(); i++)
            {
                if (m[v[i]] == 2)
                {
                    // v1.push_back(v[i]);
                    cout << v[i] << " ";
                }
            }

            for (int j = v.size() - 1; j >= 0; j--)
            {
                cout << v[j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}