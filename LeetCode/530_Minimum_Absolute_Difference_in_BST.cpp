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
    int ans = 1e9;
    int val = -1;
    void dfs(TreeNode* root) 
    {
        if (root->left)
        {
            dfs(root->left);
        }
        if (val >= 0)
        {
            ans = min(ans, abs(root->val - val));
        }
        val = root->val;
        if (root->right)
        {
            dfs(root->right);
        }
    }
    
    int getMinimumDifference(TreeNode* root) 
    {
        dfs(root);
        
        return ans;
    }
};