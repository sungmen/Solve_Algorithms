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
    bool isUnivalTree(TreeNode* root) 
    {
        if (! root) return true;
        
        bool chk = 1;
        
        if (root->left)
        {
            chk = isUnivalTree(root->left) && chk && root->left->val == root->val;
        }
        if (root->right)
        {
            chk = isUnivalTree(root->right) && chk && root->right->val == root->val;
        }
        
        return chk;
    }
};