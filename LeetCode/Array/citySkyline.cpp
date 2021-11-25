#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxc;
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int maxHt[grid.size()][grid[0].size()];
        int maxHt2[grid.size()][grid[0].size()];
        int final[grid.size()][grid[0].size()];
        for (int i = 0; i < grid.size(); i++)
        {

            int maxr = 0;
            // int maxc = 0;

            for (int j = 0; j < grid[0].size(); j++)
            {
                maxr = max(maxr, grid[i][j]);
                // maxc =
            }

            for (int k = 0; k < grid[0].size(); k++)
            {
                maxHt[i][k] = maxr;
            }
        }
        for (int i = 0; i < grid.size(); i++)
        {

            // int maxr = 0;
            int maxc = 0;

            for (int j = 0; j < grid[0].size(); j++)
            {
                maxc = max(maxc, grid[j][i]);
                // maxc =
            }
            for (int k = 0; k < grid[0].size(); k++)
            {
                maxHt2[k][i] = maxc;
            }

            for (int k = 0; k < grid.size(); k++)
            {
                for (int kk = 0; kk < grid[0].size(); kk++)
                {
                    if (maxHt[k][kk] < maxHt2[k][kk])
                    {
                        final[k][kk] = maxHt[k][kk];
                    }
                    else
                    {
                        final[k][kk] = maxHt2[k][kk];
                    }
                }
            }
        }
        int diff = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                // cout << final[i][j] << " ";
                if (final[i][j] > grid[i][j])
                {
                    diff += final[i][j] - grid[i][j];
                }
            }
            // cout << endl;
        }
        return diff;
    }
};
// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     vector<vector<int>> grid;
//     grid = {{3, 0, 8, 4}, {2, 4, 5, 7}, {9, 2, 6, 3}, {0, 3, 1, 0}};
//     int maxHt[grid.size()][grid[0].size()];
//     int maxHt2[grid.size()][grid[0].size()];
//     int final[grid.size()][grid[0].size()];
//     for (int i = 0; i < grid.size(); i++)
//     {

//         int maxr = 0;
//         // int maxc = 0;

//         for (int j = 0; j < grid[0].size(); j++)
//         {
//             maxr = max(maxr, grid[i][j]);
//             // maxc =
//         }

//         for (int k = 0; k < grid[0].size(); k++)
//         {
//             maxHt[i][k] = maxr;
//         }
//     }
//     for (int i = 0; i < grid.size(); i++)
//     {

//         // int maxr = 0;
//         int maxc = 0;

//         for (int j = 0; j < grid[0].size(); j++)
//         {
//             maxc = max(maxc, grid[j][i]);
//             // maxc =
//         }
//         for (int k = 0; k < grid[0].size(); k++)
//         {
//             maxHt2[k][i] = maxc;
//         }

//         for (int k = 0; k < grid.size(); k++)
//         {
//             for (int kk = 0; kk < grid[0].size(); kk++)
//             {
//                 if (maxHt[k][kk] < maxHt2[k][kk])
//                 {
//                     final[k][kk] = maxHt[k][kk];
//                 }
//                 else
//                 {
//                     final[k][kk] = maxHt2[k][kk];
//                 }
//             }
//         }
//     }
//     int diff = 0;

//     for (int i = 0; i < grid.size(); i++)
//     {
//         for (int j = 0; j < grid[0].size(); j++)
//         {
//             // cout << final[i][j] << " ";
//             if (final[i][j] > grid[i][j])
//             {
//                 diff += final[i][j] - grid[i][j];
//             }
//         }
//         // cout << endl;
//     }
//     cout << diff;
//     return 0;
// }