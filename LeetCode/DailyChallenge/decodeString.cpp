#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout << ('3' - '0') * 2 << endl;

//     return 0;
// }

class Solution {
public:
    string calc(string &s, int t)
    {
        for (int i = s.size(); --t; s += s.substr(0, i));
        return s;

    }


    string decodeString(string s) {
        stack<pair<string, string>> ss;
        string temp = "", word = "";
        for (auto &i : s)
        {
            if (isalpha(i))
                word += i;
            else if (isdigit(i))
                temp += i;
            else if (i == '[')
                ss.push({move(temp), move(word)});
            else {
                auto [cnt, prev] = ss.top();
                ss.pop();
                word = prev + calc(word, stoi(cnt));
            }
        }
        return word;



    }
};