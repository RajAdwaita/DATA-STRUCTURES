// #include <bits/stdc++.h>
// using namespace std;
// class Solution
// {
// public:
//     int getMaximumGenerated(int n)
//     {
//         vector<int> v(n + 1);
//         v[0] = 0;
//         v[1] = 1;
//         for (int i = 1; i <= n; i++)
//         {
//             if (2 * i >= 2 && 2 * i <= n)
//                 v[i * 2] = v[i];
//             else
//                 break;
//             // if (v.size() >= n + 1)
//             // {
//             //     return *max_element(v.begin(), v.end());
//             // }
//             if (((2 * i) + 1) >= 2 & ((2 * i) + 1) <= n)
//                 v[(i * 2) + 1] = v[i] + v[i + 1];
//             else
//                 break;
//         }
//         return *max_element(v.begin(), v.end());
//     }
// };

// // int main()
// // {
// //     std::ios::sync_with_stdio(false);
// //     cin.tie(nullptr);

// //     return 0;
// // }

class Solution
{
public:
    int getMaximumGenerated(int n)
    {
        }
};