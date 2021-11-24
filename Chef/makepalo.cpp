// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         if (n == 1)
//         {
//             cout << "0" << endl;
//             continue;
//         }
//         else
//         {

//             vector<int> a(n);
//             vector<int> odd;
//             vector<int> even;
//             for (int i = 0; i < n; i++)
//             {
//                 cin >> a[i];
//                 if (a[i] % 2 == 0)
//                     even.push_back(a[i]);
//                 else
//                     odd.push_back(a[i]);
//             }
//             sort(odd.begin(), odd.end(), greater<int>());
//             int changes = 0;
//             if (odd.size() == 1)
//                 changes = 0;
//             else
//             {
//                 for (int j = 0; j < odd.size() - 1; j += 2)
//                 {

//                     changes++;
//                     odd[j] += odd[j + 1];
//                     odd[j + 1] = 0;
//                 }
//             }
//             cout << changes << endl;
//         }
//     }

//     return 0;
// }

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

        vector<int> a(n);
        int c = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2 != 0)
            {
                c++;
            }
        }

        cout << c / 2 << endl;
    }

    return 0;
}