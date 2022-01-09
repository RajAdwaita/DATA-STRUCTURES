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
    void dfs(TreeNode *root, int &max_sum, int &cur_sum)
    {
        if (root == NULL)
        {
            return;
        }
        cur_sum += root->val;
        if (root->left == NULL && root->right == NULL)
        {
            max_sum = max(max_sum, cur_sum);
            return;
        }
        dfs(root->left, max_sum, cur_sum);
        dfs(root->right, max_sum, cur_sum);
    }
    int goodNodes(TreeNode *root)
    {
        int ans = 0;
        dfs(root, INT_MIN, ans);
        return ans;
    }
};