// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
// Example 2:

// Input: root = [1]
// Output: [[1]]
// Example 3:

// Input: root = []
// Output: []

// Constraints:

// The number of nodes in the tree is in the range [0, 2000].
// -1000 <= Node.val <= 1000

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void printLevelOrder(TreeNode *root, vector<vector<int>> &ans)
    {
        int h = maxDepth(root);
        int i;
        for (i = 1; i <= h; i++)
        {
            vector<int> temp;
            printCurrentLevel(root, i, temp);
            ans.push_back(temp);
        }
    }

    /* Print nodes at a current level */
    void printCurrentLevel(TreeNode *root, int level, vector<int> &temp)
    {
        if (root == NULL)
            return;
        if (level == 1)
            temp.push_back(root->val);
        else if (level > 1)
        {
            printCurrentLevel(root->left, level - 1, temp);
            printCurrentLevel(root->right, level - 1, temp);
        }
    }
    int maxDepth(TreeNode *root)
    {

        if (root == nullptr)
            return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        if (lh > rh)
        {
            return (lh + 1);
        }
        return rh + 1;
    }
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        vector<vector<int>> ans;

        printLevelOrder(root, ans);

        return ans;
    }
};