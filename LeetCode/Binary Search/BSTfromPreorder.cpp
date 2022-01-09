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
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        TreeNode *root = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); i++)
        {
            TreeNode *temp = root;
            while (temp)
            {
                if (temp->val > preorder[i])
                {
                    if (temp->left)
                    {
                        temp = temp->left;
                    }
                    else
                    {
                        temp->left = new TreeNode(preorder[i]);
                        break;
                    }
                }
                else
                {
                    if (temp->right)
                    {
                        temp = temp->right;
                    }
                    else
                    {
                        temp->right = new TreeNode(preorder[i]);
                        break;
                    }
                }
            }
        }
        return root;
    }
};