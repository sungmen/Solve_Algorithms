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
  vector<vector<int>> v;

  void dfs(TreeNode *root, vector<int> d, int num) {
    if (root == nullptr)
      return;
    d.push_back(num);
    if (root->left == nullptr && root->right == nullptr) {
      v.push_back(d);
      return;
    }
    dfs(root->left, d, ++num);
    dfs(root->right, d, ++num);
  }

  int countPairs(TreeNode *root, int distance) {
    int res = 0;
    vector<int> d;
    int num = 0;
    dfs(root, d, 0);
    int idx = 0;
    for (int i = 0; i < v.size(); i++) {
      for (int j = i + 1; j < v.size(); j++) {
        vector<int> p = v[i];
        vector<int> p2 = v[j];
        int t = min(p.size(), p2.size());
        int k = 0;
        for (k = 0; k < t; k++) {
          if (p[k] != p2[k])
            break;
        }
        int val1 = p.size() - k;
        int val2 = p2.size() - k;
        if (distance >= val1 + val2) {
          res++;
        }
      }
    }
    return res;
  }
};
