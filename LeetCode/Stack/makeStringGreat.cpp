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
    string makeGood(string s)
    {
        string res = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (res.size() && res.back() == s[i] && (res.size() == 1 || res[res.size() - 2] != s[i]))
            {
                res.pop_back();
            }
            else
            {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};