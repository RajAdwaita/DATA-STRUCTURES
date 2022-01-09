// class Solution
// {
// public:
//     void reverseString(vector<char> &s)
//     {
//         for (int i = 0, j = s.size() - 1; i <= j; i++, j--)
//         {
//             swap(s[i], s[j]);
//         }
//     }
// }:

#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "Adwaita";
    for (int i = 0, j = s.size() - 1; i <= j; i++, j--)
    {
        swap(s[i], s[j]);
    }
    // return 0;
    cout << s;
}