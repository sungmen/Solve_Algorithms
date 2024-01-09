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
  void findNode(TreeNode *root, vector<int> &v) {
    if (root == nullptr)
      return;
    findNode(root->left, v);
    v.push_back(root->val);
    findNode(root->right, v);
  }

  vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries) {
    vector<int> v;
    findNode(root, v);
    vector<vector<int>> res;
    for (auto query : queries) {
      if (v[0] > query) {
        res.push_back({-1, v[0]});
        continue;
      } else if (v.back() < query) {
        res.push_back({v.back(), -1});
        continue;
      }
      auto it = lower_bound(v.begin(), v.end(), query);
      int position = it - v.begin();
      int t = v[position];
      if (query == v[position])
        res.push_back({t, t});
      else
        res.push_back({v[position - 1], t});
    }
    return res;
  }
};
