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
  void search(TreeNode *root, vector<int> &d) {
    if (root == nullptr)
      return;
    search(root->left, d);
    d.push_back(root->val);
    search(root->right, d);
  }

  void change(TreeNode *root, unordered_map<int, int> &um) {
    if (root == nullptr)
      return;
    change(root->left, um);
    root->val = um[root->val];
    change(root->right, um);
  }

  void recoverTree(TreeNode *root) {
    vector<int> d, v;
    search(root, d);
    v = d;
    sort(d.begin(), d.end());
    unordered_map<int, int> um;
    for (int i = 0; i < d.size(); i++) {
      um[d[i]] = v[i];
    }
    change(root, um);
  }
};
