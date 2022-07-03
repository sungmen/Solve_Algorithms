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
private:
    int ans = 1e9, tmp = -1;
public:
    
    void dfs(TreeNode* root) {
        if (root->left) {
            dfs(root->left);
        }
        if (tmp >= 0) ans = min(root->val - tmp, ans);
        tmp = root->val;
        if (root->right) {
            dfs(root->right);
        }
    }
    
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        
        return ans;
    }
};