// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// int main()
// {
//     int t;
//     cin >> t;
//     ll m, n, q;
//     while (t--)
//     {
//         cin >> n >> m >> q;
//         char sign;
//         ll pos = 0;
//         ll neg = 0;
//         int val;
//         int a, b, c, d;
//         vector<int> person;
//         unordered_map<int, char> check;
//         int fl = -1;
//         for (int i = 0; i < q; i++)
//         {
//             cin >> sign >> val;
//             person.push_back(val);
//             if (val > n || val < 0)
//             {
//                 goto cond1;
//                 fl = 0;
//             }

//             if (sign == '+')
//             {
//                 pos++;
//                 if (check[val] == '-')
//                 {
//                     goto cond1;
//                     fl = 0;
//                 }
//             }
//             else
//             {
//                 neg++;
//             }

//             if (pos - neg > m)
//             {
//                 goto cond1;
//                 fl = 0;
//             }
//             check[val] = sign;
//         }
//         if (fl == -1)
//         {
//             cout << "Consistent" << endl;
//             break;
//         }
//     cond1:
//         cout << "Inconsistent" << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int t;
    cin >> t;
    ll m, n, q;
    while (t--)
    {
        cin >> n >> m >> q;
        unordered_set<int> bus;

        int flag = 1;

        for (int i = 0; i < q; i++)
        {
            char sign;
            int val;
            cin >> sign >> val;

            if (flag == 1)
            {
                if (sign == '-')
                {
                    if (bus.find(val) != bus.end())
                    {
                        bus.erase(val);
                    }
                    else
                    {
                        flag = 0;
                    }
                }
                else
                {
                    if ((int)bus.size() >= m)
                    {
                        flag = 0;
                    }
                    else
                    {
                        bus.insert(val);
                    }
                }
            }
        }
        if (flag == 0)
        {
            cout << "Inconsistent" << endl;
        }
        else
        {
            cout << "Consistent" << endl;
        }
    }
    return 0;
}