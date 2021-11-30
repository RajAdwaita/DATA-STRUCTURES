#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k)
    {
        map<int, set<int>> m;
        set<int> temp;
        map<int, int> mp;
        vector<int> final(k, 0);

        for (int i = 0; i < logs.size(); i++)
        {
            m[logs[i][0]].insert(logs[i][1]);
            // temp.insert(logs[])
        }
        for (auto x = m.begin(); x != m.end(); x++)
        {
            mp[x->second.size()]++;
        }
        for (auto x = mp.begin(); x != mp.end(); x++)
        {
            final[x->first - 1] = x->second;
        }
        return final;
    }
};

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }