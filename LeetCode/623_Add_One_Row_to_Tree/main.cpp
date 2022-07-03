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
    void insert(TreeNode* root, int v, int d) {
        if (d == 2) {
            if (root->left != nullptr) {
                TreeNode* tmp = new TreeNode(v);
                tmp->left = root->left;
                root->left = tmp;
            } else {
                TreeNode* tmp = new TreeNode(v);
                root->left = tmp;                
            }
            if (root->right != nullptr) {
                TreeNode* tmp = new TreeNode(v);
                tmp->right = root->right;
                root->right = tmp;
            } else {
                TreeNode* tmp = new TreeNode(v);
                root->right = tmp;                
            }
            return;
        }
        if (root->left != nullptr) {
            insert(root->left, v, d-1);
        }
        if (root->right != nullptr) {
            insert(root->right, v, d-1);
        }
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d==1) {
            TreeNode *tmp = new TreeNode(v);
            tmp->left = root;
            return tmp;
        } else {
            insert(root, v, d);
        }
        return root;
    }
};