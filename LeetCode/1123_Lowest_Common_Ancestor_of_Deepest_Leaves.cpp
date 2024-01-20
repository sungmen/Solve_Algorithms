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
  map<int, vector<vector<TreeNode *>>> m;

  void findDep(TreeNode *root, int dept, vector<TreeNode *> v) {
    if (root == nullptr)
      return;
    v.push_back(root);
    if (root->left == nullptr && root->right == nullptr) {
      m[dept].push_back(v);
    }
    findDep(root->left, dept + 1, v);
    findDep(root->right, dept + 1, v);
  }

  TreeNode *search(vector<vector<TreeNode *>> v) {
    vector<TreeNode *> d = v[0];
    for (int idx = 1; idx < v.size(); idx++) {
      int j = 0;
      for (; j < min(d.size(), v[idx].size()); j++) {
        if (d[j] != v[idx][j])
          break;
      }
      d = vector<TreeNode *>(v[idx].begin(), v[idx].begin() + j);
    }

    return d[d.size() - 1];
  }

  TreeNode *lcaDeepestLeaves(TreeNode *root) {
    vector<TreeNode *> v;
    findDep(root, 1, v);
    auto it = m.end();
    it--;
    if (it->second.size() == 1)
      return it->second[0][it->second[0].size() - 1];

    return search(it->second);
  }
};
