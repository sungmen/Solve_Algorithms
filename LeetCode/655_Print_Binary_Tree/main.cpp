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
    int depth = 0;
    vector<vector<string>> answer;
    void deep (TreeNode* root, int idx) {
        depth = max(depth, idx);
        if (root->left) deep(root->left, idx+1);
        if (root->right) deep(root->right, idx+1);
    }
    void dfs (TreeNode* root, int dep, int l, int r) {
        int mid = (r + l) / 2;
        answer[dep][mid] = to_string(root->val);
        if (root->left) dfs(root->left, dep + 1, l, mid);
        if (root->right) dfs(root->right, dep + 1, mid, r);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        // 2^(n-1) + 1
        deep(root, 1);
        int len = (1<<(depth))-1;
        answer.resize(depth, vector<string>(len, ""));
        dfs(root, 0, 0, len);
        return answer;
    }
};