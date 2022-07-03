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
    string ans = "";
    
    void dfs(TreeNode* root)
    {
        ans += to_string(root->val);        
        
        if (nullptr != root->left)
        {        
            
            ans += '(';
            dfs(root->left);
            ans += ')';
        }
        
        if (nullptr != root->right)
        {
            if (nullptr == root->left)
            {
                ans += "()";
            }
            
            ans += '(';
            dfs(root->right);
            ans += ')';
        }
        
    }
    
    string tree2str(TreeNode* root) 
    {
        dfs(root);
        
        return ans;
    }
};