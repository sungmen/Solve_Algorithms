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
    void insert(TreeNode* root, int val) {
        if (root -> val < val) {
            if (root->right == nullptr) {
                TreeNode* tmp = new TreeNode(val);
                root->right = tmp;
            } else {
                insert(root->right, val);   
            }
        } else {
            if (root->left == nullptr) {
                TreeNode* tmp = new TreeNode(val);
                root->left = tmp;
                return;
            } else {
                insert(root->left, val);
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            TreeNode* tmp = new TreeNode(val);
            return tmp;
        }
        insert(root, val);
        return root;
    }
};