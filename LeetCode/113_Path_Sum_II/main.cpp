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
    vector<vector<int>> res;
    int targetSum;
    
public:
    void dfs(TreeNode* root, vector<int> v, int sum) {
        v.push_back(root->val);
        sum += root->val;
        
        if (root->left == nullptr && root->right == nullptr && sum == targetSum) {
            res.push_back(v);
            return;
        }
        
        if (root->left != nullptr) {
            dfs(root->left, v, sum);
        }
        
        if (root->right != nullptr) {
            dfs(root->right, v, sum);
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        this->targetSum = targetSum;
        if (root == nullptr) return {};
        dfs(root, {}, 0);
        return res;
    }
};