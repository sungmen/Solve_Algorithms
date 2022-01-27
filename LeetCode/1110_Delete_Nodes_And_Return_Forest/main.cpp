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
    map<int, int> m;
    vector<TreeNode*> answer;
    TreeNode* dfs (TreeNode* root, bool check) {
        bool chk = m[root->val];
        if (check && !chk) answer.push_back(root);
        if (root->left) {
            root->left = dfs(root->left, chk);
        }
        if (root->right) {
            root->right = dfs(root->right, chk);
        }
        return chk ? nullptr : root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (auto del : to_delete) {
            m[del] = 1;
        }
        dfs(root, 1);
        return answer;
    }
};