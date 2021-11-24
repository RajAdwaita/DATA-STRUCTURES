// Chef has an array A having N elements.Chef wants to make all the elements of the array equal by repeating the following move.

//     Choose any integer K between 1 and
//     N(inclusive).Then choose K distinct indices i1,
//     i2,…, iK, and increase the values of Ai1, Ai2,…, AiK by 1. Find the minimum number of moves required to make all the elements of the array equal.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        set<int> s;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
            s.insert(x);
        }
        sort(v.begin(), v.end());
        cout << v[n - 1] - v[0] << endl;

        // if (s.size() == 1)
        // {
        //     cout << 0 << endl;
        // }
        // else
        // {
        //     vector<int> v1;

        //     sort(v.begin(), v.end());
        //     int ans = 0;
        //     for (int i = 0; i < n; i++)
        //     {
        //         if (v[i] != v[n - 1])
        //         {
        //             v1.push_back(v[i]);
        //         }
        //     }

        //     for (int i = 0; i < v1.size(); i++)
        //     {
        //         if (v1[i] < v1[v1.size() - 1])
        //         {
        //             ans++;
        //         }
        //     }
        // }
    }
    return 0;
}