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
  TreeNode *tree(vector<int> &v, int l, int r) {
    if (l > r)
      return nullptr;
    TreeNode *t = new TreeNode();
    int m = (l + r) / 2;
    t->left = tree(v, l, m - 1);
    t->right = tree(v, m + 1, r);
    t->val = v[m];
    return t;
  }

  void search(vector<int> &v, TreeNode *root) {
    if (root == nullptr)
      return;
    search(v, root->left);
    v.emplace_back(root->val);
    search(v, root->right);
  }

  TreeNode *balanceBST(TreeNode *root) {
    vector<int> v;
    search(v, root);
    TreeNode *t = tree(v, 0, v.size() - 1);
    return t;
  }
};
