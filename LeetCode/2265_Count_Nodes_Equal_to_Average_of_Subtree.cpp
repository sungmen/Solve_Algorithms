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
    int res = 0;
    
    pair<int, int> dfs(TreeNode* root) {
        int t = 1, ans = root->val;
        if (root->left) {
            pair<int, int> p = dfs(root->left);
            t += p.first;
            ans += p.second;
        }
        if (root->right) {
            pair<int, int> p = dfs(root->right);
            t += p.first;
            ans += p.second;
        }
        if (root->val == (ans / t)) {
            res ++;
        }
        return {t, ans};        
    }
    
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return res;
    }
};