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
    int max_ = INT_MIN;
    vector<int> ans;
    unordered_map<int, int> m;
    vector<int> findMode(TreeNode* root) {
        findMin(root);
        for (auto i : m) {
            if (i.second == max_) {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
    
    void findMin(TreeNode* root) {
        max_ = max(max_, ++m[root->val]);
        if (root->left) {
            findMin(root->left);
        }
        if (root->right) {
            findMin(root->right);
        }
    }
};