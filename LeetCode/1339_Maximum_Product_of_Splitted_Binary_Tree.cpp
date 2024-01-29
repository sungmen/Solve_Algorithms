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
  const int MOD = 1e9 + 7;

  long long dfs(TreeNode *root) {
    if (root == nullptr)
      return 0;
    root->val += dfs(root->left);
    root->val += dfs(root->right);
    return root->val;
  }

  long long countNum(long long &curN, long long &num, long long &ans) {
    long long curNum = num - curN;
    long long tmpAns = ((long long)curNum * (long long)curN);
    return max(ans, tmpAns);
  }

  void countMaxNum(TreeNode *root, long long &ans, long long &num) {
    if (root->left != nullptr) {
      long long cur = root->left->val;
      ans = countNum(cur, num, ans);
      countMaxNum(root->left, ans, num);
    }
    if (root->right != nullptr) {
      long long cur = root->right->val;
      ans = countNum(cur, num, ans);
      countMaxNum(root->right, ans, num);
    }
  }

  int maxProduct(TreeNode *root) {
    long long num = dfs(root);
    long long ans = 0;
    countMaxNum(root, ans, num);
    return ans % MOD;
  }
};
