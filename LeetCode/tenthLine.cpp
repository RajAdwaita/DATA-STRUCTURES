#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int x = 0;
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;
        if (root->left == nullptr && root->right == nullptr)
        {
            if (root->val == targetSum)
                return true;
            else
                return false;
        }
        if (root->left != nullptr)
        {
            if (hasPathSum(root->left, targetSum - root->val))
                return true;
        }
        if (root->right != nullptr)
        {
            if (hasPathSum(root->right, targetSum - root->val))
                return true;
        }
        return false;
    }
};
// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }