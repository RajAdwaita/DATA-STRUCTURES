#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }

class Solution
{
public:
    int calc(vector<int> v, int x)
    {
        int to = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == x)
                to++;
        }
        return to;
    }
    int findJudge(int n, vector<vector<int>> &trust)
    {
        int count = 0;
        set<int> s;
        for (int i = 0; i < trust.size(); i++)
        {
            int se = trust[i][0];
            s.insert(se);
        }
        if (s.size() == n)
            return -1;
        vector<int> judge;
        for (int i = 0; i < trust.size(); i++)
        {
            judge.push_back(trust[i][1]);
        }
        set<int> ss;
        for (int i = 0; i < judge.size(); i++)
        {
            ss.insert(judge[i]);
        }
        set<int>::iterator sets = ss.begin();
        vector<int> sss;
        for (int i = 0; i < ss.size(); i++)
        {
            sets++;
            sss.push_back(*sets);
        }

        for (int i = 0; i < sss.size(); i++)
        {
            int pos = sss[i];
            int ccc = calc(judge, pos);
            if (ccc == n - 1)
                return pos;
        }
        return -1;
    }
};