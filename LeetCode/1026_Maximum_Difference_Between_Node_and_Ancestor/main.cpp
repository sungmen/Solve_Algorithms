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
    int res = 0;
    
public:
    void dfs(TreeNode* root, vector<int> v) {
        int r = root->val;
        for (int i = 0; i < v.size(); i++) {
            if (res < abs(r - v[i])) {
                res = abs(r - v[i]);
            }
        }
        v.push_back(r);
        
        if (root->left != nullptr) {
            dfs(root->left, v);    
        }
        
        if (root->right != nullptr) {
            dfs(root->right, v);
        }
    }
    
    int maxAncestorDiff(TreeNode* root) {
        vector<int> v;
        dfs(root, v);
        
        return res;
    }
};