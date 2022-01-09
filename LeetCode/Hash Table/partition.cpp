#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> lastPos(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            lastPos[s[i] - 'a'] = i;
        }
        vector<int> res;
        int i = 0, end = 0;
        start = i;
        while (i < s.size())
        {
            end = max(end, lastPos[s[i] - 'a']);
            if (end == i)
            {
                res.push_back(end - start + 1);
                start = i + 1;
            }
            i++;
        }
        return res;
    }
};

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }