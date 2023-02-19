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
    bool dfs(TreeNode* root, int limit, int sum)
    {
        int val = root->val;
        if (!root->left && !root->right)
        {
            return limit <= sum + val;
        }
        bool c1 = false, c2 = false;
        if (root->left)
        {
            c1 = dfs(root->left, limit, sum + val);
            if (! c1)
                root->left = nullptr;
            
        }
        if (root->right)
        {
            c2 = dfs(root->right, limit, sum + val);
            if (! c2)
                root->right = nullptr;
        }
        return c1 | c2;
    }

    TreeNode* sufficientSubset(TreeNode* root, int limit) 
    {
        return dfs(root, limit, 0) ? root : nullptr;
    }
};