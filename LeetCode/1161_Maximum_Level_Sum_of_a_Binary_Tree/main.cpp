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
private:
    vector<int> v;
    
public:
    void dfs(TreeNode* root, int level) {
        if (v.size() == level) {
            v.push_back(root->val);
        } else {
            v[level] += root->val;
        }
        
        if (root->left != nullptr) {
            dfs(root->left, level + 1);
        }
        
        if (root->right != nullptr) {
            dfs(root->right, level + 1);
        }
    }
    
    int maxLevelSum(TreeNode* root) {
        dfs(root, 0);
        int m = INT_MIN, res = 0;
        for (int i = 0; i < v.size(); i++) {
            if (m < v[i]) {
                m = v[i];
                res = i;
            }
        }
        return res + 1;
    }
};