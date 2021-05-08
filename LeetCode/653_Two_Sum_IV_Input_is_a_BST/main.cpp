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
    map<int, int> m;
    int cnt = 1;
public:
    void bst(TreeNode* root) {
        if (root->left != nullptr) bst(root->left);
        m[root->val] = cnt++;
        if (root->right != nullptr) bst(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        if (root != nullptr)bst(root);
        for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
            if (m.find(k - it->first) != m.end()) {
                if (it->second != m.find(k - it->first)->second)
                    return true;
            }
        }
        return false;
    }
};