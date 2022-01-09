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
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int emp = 0;

        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                }
                if (grid[i][j] == 0)
                {
                    emp++;
                }
            }
        }

        int arr1[] = {-1, 0, 1, 0};
        int arr2[] = {0, -1, 0, 1};
        int newx, newy;
        int time = 0;
        int x, y;
        int rot = 0;
        pair<pair<int, int>, int> p;

        while (!q.empty())
        {
            p = q.front();
            x = p.first.first;
            y = p.first.second;
            time = p.second;
            q.pop();
            rot++;

            for (int i = 0; i < 4; i++)
            {
                newx = x + arr1[i];
                newy = y + arr2[i];

                if (newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] == 1)
                {
                    grid[newx][newy] = 2;
                    q.push({{newx, newy}, time + 1});
                }
            }
        }

        if (rot + emp == m * n)
        {
            return time;
        }
        else
        {
            return -1;
        }
    }
};