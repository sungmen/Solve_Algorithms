class Solution {
public:
    int dfs(TreeNode* root, int& res) {
        if (root == nullptr) return 0;
        int left = max(dfs(root->left, res), 0);
        int right = max(dfs(root->right, res), 0);
        res = max(res, left + right + root->val);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        dfs(root, result);
        return result;
    }
};