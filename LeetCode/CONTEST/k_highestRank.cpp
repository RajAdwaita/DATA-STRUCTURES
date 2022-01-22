// represent the following:

//     0 represents a wall that you cannot pass through.
//     1 represents an empty cell that you can freely move to and from.
//     All other positive integers represent the price of an item in that cell. You may also freely move to and from these item cells.

// It takes 1 step to travel between adjacent grid cells.

// You are also given integer arrays pricing and start where pricing = [low, high] and start = [row, col] indicates that you start at the position (row, col) and are interested only in items with a price in the range of [low, high] (inclusive). You are further given an integer k.

// You are interested in the positions of the k highest-ranked items whose prices are within the given price range. The rank is determined by the first of these criteria that is different:

//     Distance, defined as the length of the shortest path from the start (shorter distance has a higher rank).
//     Price (lower price has a higher rank, but it must be in the price range).
//     The row number (smaller row number has a higher rank).
//     The column number (smaller column number has a higher rank).

// Return the k highest-ranked items within the price range sorted by their rank (highest to lowest). If there are fewer than k reachable items within the price range, return all of them.

class Solution
{
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>> &grid, vector<int> &pricing, vector<int> &start, int k)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        dp[start[0]][start[1]] = 1;
        int count = 0;
        int xx, yy;

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;

            if (count == k)
                break;

            q.pop();

            for (int i = 0; i < 4; i++)
            {
                xx += dir[i][0];
                yy += dir[i][1];

                if (xx < 0 || xx >= n || yy < 0 || yy >= m)
                    continue;
                else
                {
                    if (dp[xx][yy] != 0 && grid[xx][yy] >= pricing[0] && grid[xx][yy] <= pricing[1])
                    {
                        dp.push_back(dp[xx][yy]);
                        q.push({xx, yy});
                    }
                }
            }
        }
        return dp;
    }
};