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
    vector<int> answer;
    void postorder(TreeNode* root) {
        if (root->left != nullptr) {
            postorder(root->left);
        }
        if (root->right != nullptr) {
            postorder(root->right);
        }
        answer.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        postorder(root);
        return answer;
    }
};