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
    int sumOfLeftLeaves(TreeNode* root) {
        queue<pair<TreeNode*, bool>> q;
        q.push({root, false});
        int res = 0;
        while(!q.empty()) {
            pair<TreeNode*, bool> cur = q.front();
            q.pop();
            if (cur.second && cur.first->left == nullptr && cur.first->right == nullptr) {
                res += cur.first->val;
                continue;
            }
            if (cur.first->left != nullptr) {
                q.push({cur.first->left, true});
            }
            if (cur.first->right != nullptr) {
                q.push({cur.first->right, false});
            }
        }
        return res;
    }
};