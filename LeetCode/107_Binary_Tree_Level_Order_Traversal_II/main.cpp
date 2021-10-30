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
    vector<vector<int>> res;
    
    void dfs(TreeNode* root, int idx) {
        if (res.size() < idx) {
            vector<int> v;
            v.push_back(root->val);
            res.push_back(v);
        } else {
            res[idx - 1].push_back(root->val);
        }
        if (root->left != nullptr) {
            dfs(root->left, idx + 1);
        }
        if (root->right != nullptr) {
            dfs(root->right, idx + 1);
        }
    }
    
    void reverseTreeNode() {
        for (int i = 0; i < res.size() / 2; ++i) {
            swap(res[i], res[res.size() - i - 1]);
        }
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) return {};
        dfs(root, 1);
        reverseTreeNode();
        return res;
    }
};