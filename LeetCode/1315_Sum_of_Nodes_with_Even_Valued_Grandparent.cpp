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
    int answer = 0;
    
    void getvalue(TreeNode* root, int deep) {
        if (deep == 2) {
            answer += root->val;
            return;
        }
        if (root->left) getvalue(root->left, deep + 1);
        if (root->right) getvalue(root->right, deep + 1);
    }
    
    void dfs(TreeNode* root) {
        if (!(root->val % 2)) getvalue(root, 0);
        if (root->left) dfs(root->left);
        if (root->right) dfs(root->right);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root);
        return answer;    
    }
};