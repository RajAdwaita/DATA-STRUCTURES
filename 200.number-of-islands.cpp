/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
        if (grid[i][j] == '0' ||
            grid[i][j] == '2')
            return;
        grid[i][j] = '2';

        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int temp = 0;
        int island = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    ++island;
                }
            }
        }
        return island;
    }
};
// @lc code=end
