#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string cc1 = "";
        string cc2 = "";
        for (auto i : word1)
        {
            cc1 += i;
        }
        for (auto i : word2)
        {
            cc2 += i;
        }

        if (cc1 == cc2)
            return true;
        else
            return false;
    }
};

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     string word1[] = {"ab", "c"};
//     // string word1 = {"ab", "c"};
//     string concat1 = "";
//     for (int i = 0; i < 2; i++)
//     {
//         concat1 += word1[i];
//     }
//     cout << concat1 << endl;
//     // cout << concat1 == "abc" << endl;

//     return 0;
// }