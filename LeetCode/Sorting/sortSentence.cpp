#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     string s = "is2 sentence4 This1 a3";

//     return 0;
// }

class Solution
{
public:
    string sortSentence(string s)
    {
        map<int, string> m;
        int len = 0;
        s = s + " ";
        string word = "";
        string temp = "";
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i + 2] != ' ')
            {
                temp += s[i];
                // cout << temp << endl;
            }
            else if (s[i + 2] == ' ')
            {
                temp += s[i];
                int x = (int)s[i + 1];
                m[x - 48] = temp;
                temp = "";
                len++;
                i += 2;
                // cout << x << " " << m[x] << endl;
            }
            // cout << temp << endl;
        }

        for (int i = 1; i <= len; i++)
        {
            // cout << m[i] << endl;
            if (i < len)
                word += m[i] + " ";
            else
            {
                word += m[i];
            }
        }
        // cout << word << endl;
        return word;

        // for (auto &i : m)
        // {

        // }
    }
};
