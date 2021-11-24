#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int l = min(word1.length(), word2.length());
        string main = "";

        for (int i = 0; i < l; i++)
        {
            main += word1[i];
            main += word2[i];
        }
        if (word1.length() > l)
        {
            for (int i = l; i < word1.length(); i++)
            {
                main += word1[i];
            }
        }
        else if (word2.length() > l)
        {
            for (int i = l; i < word2.length(); i++)
            {
                main += word2[i];
            }
        }
        return main;
    }
};

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }