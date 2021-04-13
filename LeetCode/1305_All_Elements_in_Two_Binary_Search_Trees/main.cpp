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
    vector<int> res;
public:
    void find_node(TreeNode* root) {
        res.push_back(root->val);
        if (root->left != nullptr) {
            find_node(root->left);
        }
        if (root->right != nullptr) {
            find_node(root->right);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        if (root1 != nullptr) find_node(root1);
        if (root2 != nullptr) find_node(root2);
        sort(res.begin(), res.end());
        return res;
    }
};