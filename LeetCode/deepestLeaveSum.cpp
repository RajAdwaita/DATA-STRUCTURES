#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
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
    int tot = 0;
    int height(TreeNode *p)
    {
        int hL, rL;

        if (p == NULL)
        {
            return 0;
        }

        hL = height(p->left);
        rL = height(p->right);

        if (hL > rL)
            return 1 + hL;
        else
            return 1 + rL;
    }
    void getSum(TreeNode *pp, int maxH, int depth, int &tot)
    {
        if (pp)
        {

            getSum(pp->left, maxH, depth + 1, tot);
            getSum(pp->right, maxH, depth + 1, tot);
            if (maxH == depth)
            {
                tot += pp->val;
            }
            return;
            // return tot;
            // if (pp->left == NULL && pp)
        }
    }
    int deepestLeavesSum(TreeNode *root)

    {

        int final = 0;
        int maxH = height(root);
        int depth = 1;

        getSum(root, maxH, depth, tot);
        return tot;
    }
};

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }