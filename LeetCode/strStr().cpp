#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
            return 0;
        if (haystack.empty())
            return -1;
        int i = 0, j = 0;
        while (i < haystack.size() && j < needle.size())
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                i = i - j + 1;
                j = 0;
            }
        }
        if (j == needle.size())
            return i - j;
        else
            return -1;
    }
};

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }