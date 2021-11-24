#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> processQueries(vector<int> &queries, int m)
    {
        int Ppos = 0;
        int toAdd = 0;
        vector<int> P;
        vector<int> res;

        for (int i = 0; i < m; i++)
        {
            P.push_back(i + 1);
        }

        for (int i = 0; i < queries.size(); i++)
        {
            int qpos = queries[i];
            for (int j = 0; j < P.size(); j++)
            {
                if (P[j] == qpos)
                {
                    Ppos = j;
                    toAdd = P[Ppos];
                    res.push_back(Ppos);
                    break;
                }
            }

            P.erase(P.begin() + Ppos);

            P.insert(P.begin(), toAdd);
        }
        return res;
    }
};

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     vector<int> p;
//     p.push_back(1);
//     p.push_back(2);
//     p.push_back(3);
//     p.push_back(4);
//     p.push_back(5);
//     p.push_back(6);
//     p.push_back(7);
//     p.erase(p.begin() + p[0]);
//     for (auto i : p)
//         cout << i << "   ";

//     // p.insert(p.begin(), ppos);

//     return 0;
// }