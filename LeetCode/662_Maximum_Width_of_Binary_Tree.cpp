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
    pair<unsigned long long, unsigned long long> arr[3001];
    void dfs(TreeNode* root, long long deep, unsigned long long num) {
        if (arr[deep].first == -1) {
            arr[deep].first = num;
            arr[deep].second = num;
        } else {
            arr[deep].second = num;
        }
        if (root->left != nullptr) {
            dfs(root->left, deep + 1, num * 2);
        }
        if (root->right != nullptr) {
            dfs(root->right, deep + 1, num * 2 + 1);
        }
    }
    int widthOfBinaryTree(TreeNode* root) {
        for (int i = 0; i < 3001; i++) arr[i] = {-1, -1};
        dfs(root, 0, 0);
        unsigned long long res = 0;
        for (int i = 0; i < 3001; i++) {
            res = max(res, arr[i].second - arr[i].first + 1);
        }
        return res;
    }
};