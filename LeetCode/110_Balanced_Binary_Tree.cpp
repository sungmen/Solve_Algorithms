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
    int dfs(TreeNode* root) {
        int l = 0, r = 0;
        if (root == nullptr) return 0;
        
        if (root->left != NULL) {
            l = dfs(root->left);
        }
        if (root->right != NULL) {
            r = dfs(root->right);
        }
        return 1 + max(l, r);
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        
        return (abs(dfs(root->left) - dfs(root->right)) <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }
};