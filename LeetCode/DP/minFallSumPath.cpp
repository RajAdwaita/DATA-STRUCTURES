// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

//                                                     A falling path starts at any element in the first row and
//                                                     chooses the element in the next row that is either directly below or
//                                                 diagonally left / right.Specifically,
//     the next element from position(row, col)
// will be(row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

//                                                Example 1 :

//     Input : matrix = [ [ 2, 1, 3 ], [ 6, 5, 4 ], [ 7, 8, 9 ] ] Output : 13 Explanation : There are two falling paths with a minimum sum as shown.Example 2 :

// Input : matrix = [ [ -19, 57 ], [ -40, -5 ] ] Output : -59 Explanation : The falling path with a minimum sum is shown.

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        // int n = matrix.size();
        // vector<int> dp(n, 0);
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (i == 0)
        //         {
        //             dp[j] = matrix[i][j];
        //         }
        //         else
        //         {
        //             int m = INT_MAX;
        //             for (int k = 0; k < n; k++)
        //             {
        //                 if (k != j)
        //                 {
        //                     m = min(m, dp[k]);
        //                 }
        //             }
        //             dp[j] = m + matrix[i][j];
        //         }
        //     }
        // }
        // int res = INT_MAX;
        // for (int i = 0; i < n; i++)
        // {
        //     res = min(res, dp[i]);
        // }
        // return res;

        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] += min({matrix[i - 1][max(0, j - 1)], matrix[i - 1][j], matrix[i - 1][min(n - 1, j + 1)]});
            }
        }

        return *min_element(matrix[m - 1].begin(), matrix[m - 1].end());
    }
};