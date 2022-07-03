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
class Solution {
public:
    bool dfs(TreeNode * l, TreeNode * r) {
        return (l == nullptr || r == nullptr)? (l==nullptr&&r==nullptr) ? true:false : (l->val==r->val && dfs(l->left, r->right) && dfs(l->right, r->left));        
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return dfs(root->left, root->right);
    }
};