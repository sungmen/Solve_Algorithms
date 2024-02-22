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
  TreeNode *ans = new TreeNode();

  void dfs(TreeNode *root, vector<int> v, map<int, vector<vector<int>>> &um) {
    v.push_back(root->val);
    if (root->left == nullptr && root->right == nullptr) {
      int n = v.size();
      um[-n].push_back(v);
      return;
    }
    if (root->left) {
      dfs(root->left, v, um);
    }
    if (root->right) {
      dfs(root->right, v, um);
    }
  }
  void find(TreeNode *root, int cur) {
    if (root->val == cur) {
      ans = root;
    }

    if (root->left) {
      find(root->left, cur);
    }
    if (root->right) {
      find(root->right, cur);
    }
  }
  TreeNode *subtreeWithAllDeepest(TreeNode *root) {
    map<int, vector<vector<int>>> um;
    vector<int> v;
    dfs(root, v, um);
    auto it = um.begin();
    vector<vector<int>> vi = it->second;
    int n = vi[0].size() - 1;
    int cur = -1;
    if (vi.size() == 1)
      cur = vi[0][n];
    for (int i = 1; i < vi.size(); i++) {
      while (vi[i - 1][n] != vi[i][n]) {
        n--;
      }
      cur = vi[i - 1][n];
    }
    find(root, cur);
    return ans;
  }
};
