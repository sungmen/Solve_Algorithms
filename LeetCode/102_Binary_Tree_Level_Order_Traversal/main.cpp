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
    vector<vector<int>> v;
public:
    void dfs(TreeNode* root, int deep) {
        int val = root->val;
        if (v.size() == deep) {
            v.push_back({val});
        } else {
            v[deep].push_back(val);
        }
        if (root->left != nullptr) {
            dfs(root->left, deep+1);
        }
        if (root->right != nullptr) {
            dfs(root->right, deep+1);
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        dfs(root, 0);
        return v;
    }
};