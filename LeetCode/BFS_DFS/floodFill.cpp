// An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

// You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

// To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

// Return the modified image after performing the flood fill.

// Example 1:

// Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]
// Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
// Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
// Example 2:

// Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
// Output: [[2,2,2],[2,2,2]]

// Constraints:

// m == image.length
// n == image[i].length
// 1 <= m, n <= 50
// 0 <= image[i][j], newColor < 216
// 0 <= sr < m
// 0 <= sc < n

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int m = image.size();
        int n = image[0].size();
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        vector<vector<int>> v(m, vector<int>(n));
        queue<pair<int, int>> q;

        q.push({sr, sc});
        v[sr][sc] = 1;
        int x, y, newx, newy;

        while (!q.empty())
        {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                newx = x + dx[i];
                newy = y + dy[i];

                if (newx >= 0 && newx < m && newy >= 0 && newy < n && !v[newx][newy] && image[x][y] == image[newx][newy])
                {
                    v[newx][newy] = 1;
                    q.push({newx, newy});
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[i][j])
                    image[i][j] = newColor;
            }
        }
        return image;
    }
};