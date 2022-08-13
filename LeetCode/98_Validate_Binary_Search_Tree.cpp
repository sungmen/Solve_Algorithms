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
    vector<int> v;
    
    void dfs(TreeNode* root)
    {
        if (root->left)
        {
            dfs(root->left);
        }
        
        v.push_back(root->val);
        
        if (root->right)
        {
            dfs(root->right);
        }
    }
    
    bool isValidBST(TreeNode* root) 
    {
        dfs(root);
        
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i - 1] >= v[i])
            {
                return false;
            }
        }
        
        return true;
    }
};