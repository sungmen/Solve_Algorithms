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
    set<int> s;
    void dfs(TreeNode* root) {
        s.insert(root->val);
        if (root->left != nullptr) dfs(root->left);
        if (root->right != nullptr) dfs(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        int idx = 0, res = 0;
        for (auto it = s.begin(); it != s.end() && idx < k; ++it, ++idx) {
            res = *it;
        }
        return res;
    }
};