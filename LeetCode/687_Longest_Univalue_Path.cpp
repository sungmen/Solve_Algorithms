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
    int ans = 0;
    
    int dfs(TreeNode* root)
    {
        if (! root) return 0;
        
        int lvalue = 0, lp = dfs(root->left);            
        int rvalue = 0, rp = dfs(root->right);
        
        if (root->left && root->val == root->left->val)
        {
            lvalue = lp + 1;
        }
        
        if (root->right && root->val == root->right->val)
        {
            rvalue = rp + 1;
        }
        
        if (ans < lvalue + rvalue)
        {
            ans = lvalue + rvalue;
        }
                
        return max(lvalue, rvalue);
    }
    
    int longestUnivaluePath(TreeNode* root) 
    {
        dfs(root);
        
        return ans;
    }
};