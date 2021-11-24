// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     string st;
//     unordered_map<char, char> m;
//     cin >> st;

//     for (int i = 0; i < (2 * n) - 2; i += 2)
//     {
//         m[st[i]] = st[i + 1];
//     }
//     int count{0};
//     vector<char> v;
//     for (auto i : m)
//     {
//         int flag{-1};
//         // cout << i.first << " " << i.second << endl;
//         if (toupper(i.first) != i.second)
//         {
//             count++;
//             v.push_back(i.first);
//             flag = 0;
//         }
//         if (flag == 0 && v.size() > 0)
//             for (auto j : v)
//             {
//                 if (toupper(j) == i.second)
//                 {
//                     flag = 1;
//                     count -= 1;
//                     // auto it=v.
//                     break;
//                 }
//             }
//     }
//     cout << count;
//     // return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<char, int> m;
    char s, s1;
    for (int i = 0; i < ((2 * n) - 2) / 2; i++)
    {
        cin >> s >> s1;
        if (toupper(s) != s1)
        {
            if (m.size() <= 0 || m.find(s) == m.end())
            {
                m[s] = 1;
            }

            else if (m.size() > 0 && (m.find(s) != m.end()))
            {
                auto it = m.find(s);
                it->second++;
            }

            for (auto i = m.begin(); i != m.end(); ++i)
            {
                if (toupper(i->first) == s1 && (i->second != 0))
                {
                    i->second--;
                    break;
                }
            }
        }
    }

    int ss{0};
    for (auto i = m.begin(); i != m.end(); ++i)
    {
        ss += i->second;
    }

    cout << ss;

    return 0;
}