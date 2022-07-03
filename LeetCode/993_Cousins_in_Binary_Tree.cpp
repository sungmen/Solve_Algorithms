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
    pair<int, int> x_, y_;
    int xi, yi;
    
    void dfs(TreeNode* root, int dep, int p)
    {
        if (xi == root->val)
        {
            x_ = {dep, p};
        }
        
        if (yi == root->val)
        {
            y_ = {dep, p};
        }
        
        if (root->left)
        {
            dfs(root->left, dep + 1, root->val);
        }
        if (root->right)
        {
            dfs(root->right, dep + 1, root->val);
        }
    }
    
    bool isCousins(TreeNode* root, int x, int y) 
    {
        x_ = {0, 0};
        y_ = {0, 0};
        
        xi = x;
        yi = y;
        
        dfs(root, 0, 0);
        
        if (x_.first == y_.first && x_.second != y_.second)
        {
            return true;
        }
        return false;
    }
};