// class Solution
// {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         int n = s.length();
//         int i = 0, j = 0;
//         int max = 0;
//         int arr[256] = {0};
//         while (i < n && j < n)
//         {
//             if (arr[s[j]] == 0)
//             {
//                 arr[s[j]] = 1;
//                 j++;
//                 max = max > j - i ? max : j - i;
//             }
//             else
//             {
//                 arr[s[i]] = 0;
//                 i++;
//             }
//         }
//         return max;
//     }
// };

#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << 'r' - 'a';

    return 0;
}