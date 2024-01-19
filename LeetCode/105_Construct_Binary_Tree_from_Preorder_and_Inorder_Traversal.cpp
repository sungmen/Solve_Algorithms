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
  int idx = 0;
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int l = -1,
                      int r = -1) {
    if (l > r)
      return NULL;
    l = (l == -1 ? 0 : l);
    r = (r == -1 ? preorder.size() - 1 : r);
    int i = l;
    for (; i <= r; i++)
      if (preorder[idx] == inorder[i])
        break;
    TreeNode *node = new TreeNode(preorder[idx++]);
    node->left = buildTree(preorder, inorder, l, i - 1);
    node->right = buildTree(preorder, inorder, i + 1, r);
    return node;
  }
};
