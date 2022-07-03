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
    vector<int> v;
public:
    void preOrder(TreeNode * t) {
        v.push_back(t->val);
        if (t->left != nullptr) {
            preOrder(t->left);
        }
        if (t->right != nullptr) {
            preOrder(t->right);
        }
    }
    
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        } else {
            preOrder(root);
        }
        TreeNode * tr = root;
        for (auto i = 0; i < v.size(); i++) {
            tr->val = v[i];
            if (i+1 < v.size()) {
                TreeNode * th = new TreeNode();
                tr->left = nullptr;
                tr->right = th;
                tr = tr->right;
            }
        }
    }
};