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
  int idx = -1;
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int l = -1,
                      int r = -1) {
    if (l > r)
      return nullptr;
    idx = (idx == -1 ? postorder.size() - 1 : idx);
    l = (l == -1 ? 0 : l);
    r = (r == -1 ? postorder.size() - 1 : r);
    int i = l;
    bool chk = false;
    for (; i <= r; i++) {
      if (inorder[i] == postorder[idx]) {
        chk = true;
        break;
      }
    }
    if (false == chk)
      return nullptr;
    TreeNode *node = new TreeNode(postorder[idx]);
    --idx;
    node->right = buildTree(inorder, postorder, i + 1, r);
    node->left = buildTree(inorder, postorder, l, i - 1);
    return node;
  }
};
