// Given two integers n and k, return all possible combinations of k numbers out of the range[1, n].

//         You may return the answer in any order.

//         Example 1 :

// Input : n = 4,
// k = 2 Output : [
// [ 2, 4 ],
// [ 3, 4 ],
// [ 2, 3 ],
// [ 1, 2 ],
// [ 1, 3 ],
// [ 1, 4 ],
// ] Example 2 :

// Input : n = 1,
// k = 1 Output : [[1]]

// Constraints :

// 1 <= n <= 20 1 <= k <= n

class Solution
{
public:
    void calc_disp(vector<vector<int>> &ans, vector<int> &temp, int n, int left, int k)
    {
        if (k == 0)
        {
            ans.push_back(temp);
            return;
        }

        for (int i = left; i <= n; i++)
        {
            temp.push_back(i);
            calc_disp(ans, temp, n, i + 1, k - 1);

            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> temp;
        vector<vector<int>> ans;

        // for(int i=1;i<=n;i++)
        // {
        //     temp.push_back(i);
        // }

        calc_disp(ans, temp, n, 1, k);
        return ans;
    }
};