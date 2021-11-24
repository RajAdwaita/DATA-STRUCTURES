// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// public:
//     int wiggleMaxLength(vector<int> &nums)
//     {
//         vector<int> wiggle;
//         set<int> ss;
//         for (int i = 0; i < nums.size() - 1; i++)
//         {
//             int x = nums[i + 1] - nums[i];

//             wiggle.push_back(x);
//             ss.insert(x);
//         }
//         int cc = 0;
//         if (ss.size() == 1)
//             cc = 2;

//         else
//         {
//             for (int i = 0; i < wiggle.size() - 1; i++)
//             {
//                 if (wiggle[i] > 0)
//                 {
//                     // for (int i = 0; i < wiggle.size() - 1; i++)
//                     // {
//                     if ((i % 2 == 0 && wiggle[i] > 0) && (i + 1 % 2 != 0 && wiggle[i + 1] < 0))
//                         cc += 1;
//                     // }
//                 }
//                 else if (wiggle[i] < 0)
//                 {
//                     // for (int i = 0; i < wiggle.size(); i++)
//                     // {
//                     if ((i % 2 == 0 && wiggle[i] < 0) && (i + 1 % 2 != 0 && wiggle[i + 1] > 0))
//                         cc += 1;
//                     // }
//                 }
//             }
//         }
//         return cc;
//     }
// };

// // int main()
// // {
// //     std::ios::sync_with_stdio(false);
// //     cin.tie(nullptr);

// //     return 0;
// // }

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return n;
        int ans = 1;
        int up = 1;
        int down = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
                up = down + 1;
            else if (nums[i] < nums[i - 1])
                down = up + 1;
            ans = max(ans, max(up, down));
        }
        return ans;
    }
};