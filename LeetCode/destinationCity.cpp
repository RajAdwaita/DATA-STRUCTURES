#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        set<string> s;
        vector<string> toPaths;
        for (int i = 0; i < paths.size(); i++)
        {
            s.insert(paths[i][0]);
            s.insert(paths[i][1]);
            toPaths.push_back(paths[i][0]);
        }

        
    }
};
// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }