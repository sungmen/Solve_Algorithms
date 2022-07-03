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
    void dfs(TreeNode* root, int sum) {
        sum *= 10;
        sum += root->val;
        
        if (root->left == nullptr && root->right == nullptr) {
            res += sum;
        }
        
        if (root->left != nullptr) {
            dfs(root->left, sum);
        }
        
        if (root->right != nullptr) {
            dfs(root->right, sum);
        }
    }
    
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;
        
        dfs(root, 0);
        
        return res;
    }
};