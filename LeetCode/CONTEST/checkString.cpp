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
    bool checkString(string s)
    {
        char checkB ='';
        int cc = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'b')
            {
                checkB = 'b';
                cc++;
            }
            else if (s[i] == 'a' and checkB != 'b')
            {
                cc++;
                // checkB = '';
            }
            else if (s[i] == 'a' and checkB == 'b')
            {
                return false;
                break;
            }
        }
        return true;
    }
};