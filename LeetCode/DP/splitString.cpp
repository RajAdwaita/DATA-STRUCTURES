#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int splitString(string s)
    {
        map<int, int> mp, mp1;
        int c = 0;
        for (auto &i : s)
        {
            mp1[i]++;
        }
        for (auto &i : s)
        {
            mp[i]++;
            if (mp1.find(i) != mp1.end())
            {
                if (mp1[i] == 1)
                    mp1.erase(i);
                else
                    mp1[i]--;
            }
            if (mp.size() == mp1.size())
                c++;
        }
        return c;
    }
};

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     string s = "adwaita";
//     cout << s.substr(0, 3) << endl;

//     return 0;
// }