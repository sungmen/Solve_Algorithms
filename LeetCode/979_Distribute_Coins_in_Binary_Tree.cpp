/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  int dfs(TreeNode *root, int &res) {
    if (root == nullptr)
      return 0;
    int left = dfs(root->left, res);
    int right = dfs(root->right, res);
    res += (abs(left) + abs(right));
    return left + right + root->val - 1;
  }

  int distributeCoins(TreeNode *root) {
    int ans = 0;
    dfs(root, ans);
    return ans;
  }
};
