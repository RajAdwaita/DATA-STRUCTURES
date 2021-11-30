#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (!size(matrix))
            return 0;
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();

        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int row = i, collen = n, col; row < m && matrix[row][j] == '1'; row++)
                {
                    for (col = j; col < n && matrix[row][col] == '1'; col++)
                        ;

                    collen = min(collen, col - j);
                    ans = max(ans, (row - i + 1) * collen);
                }
            }
        }
        return ans;
    }
};

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout << "10" << endl;

//     return 0;
// }