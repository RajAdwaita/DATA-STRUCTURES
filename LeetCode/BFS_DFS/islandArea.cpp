class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;
        int area;
        int arr1[] = {-1, 0, 1, 0};
        int arr2[] = {0, -1, 0, 1};
        int x, y;
        int newx, newy;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    area = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 0;
                    while (!q.empty())
                    {
                        x = q.front().first;
                        y = q.front().second;
                        q.pop();
                        area++;
                        for (int k = 0; k < 4; k++)
                        {
                            newx = x + arr1[k];
                            newy = y + arr2[k];
                            if (newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] == 1)
                            {
                                grid[newx][newy] = 0;
                                q.push({newx, newy});
                            }
                        }
                    }
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};