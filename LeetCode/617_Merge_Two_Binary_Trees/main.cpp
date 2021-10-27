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
    void dfs(TreeNode* root, TreeNode* ans) {
        ans->val += root->val;
        if (root->left != nullptr) {
            if (ans->left == nullptr) ans->left = new TreeNode(0);
            dfs(root->left, ans->left);
        }
        if (root->right != nullptr) {
            if (ans->right == nullptr) ans->right = new TreeNode(0);
            dfs(root->right, ans->right);
        }
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) return {};
        TreeNode* answer = new TreeNode();
        if (root1 != nullptr) {    
            dfs(root1, answer);
        }
        if (root2 != nullptr) {
            dfs(root2, answer);
        }
        return answer;
    }
};