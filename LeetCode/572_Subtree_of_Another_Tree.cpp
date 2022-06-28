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
    
    bool dfs(TreeNode* root, TreeNode* subRoot)
    {
        if (nullptr == root && nullptr == subRoot)
        {
            return true;
        }
        if (nullptr == root || nullptr == subRoot)
        {
            return false;
        }
        if (root->val != subRoot->val)
        {
            return false;
        }
        
        return dfs(root->left, subRoot->left) && dfs(root->right, subRoot->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if (nullptr == root && nullptr == subRoot)
        {
            return true;
        }
        if (nullptr == root)
        {
            return false;
        }
        
        return dfs(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};