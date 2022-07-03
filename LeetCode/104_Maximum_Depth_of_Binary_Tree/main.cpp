/**
*   Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum Depth of Binary Tree.
*   Memory Usage: 18.8 MB, less than 96.34% of C++ online submissions for Maximum Depth of Binary Tree.
**/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int depth = 0;
    void dfs (TreeNode * root, int cnt) {
        if (depth < cnt) depth = cnt;
        if (root->left != nullptr) {
            dfs(root->left, cnt + 1);
        }
        if (root->right != nullptr) {
            dfs(root->right, cnt + 1);
        }
    }
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        dfs(root, 1);
        return depth;
    }
};