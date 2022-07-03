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
    
    void dfs (TreeNode* root, string dept) 
    {
        dept += (root->val + '0');
        if (!root->left && !root->right) {
            for (int i = 0; i < dept.size(); ++i) {
                answer += (dept[i] == '1'? (1<<dept.size() - i - 1) : 0);
            }
            return;
        }
        if (root->left) dfs(root->left, dept);
        if (root->right) dfs(root->right, dept);
    }
    
    int sumRootToLeaf(TreeNode* root) 
    {
        dfs(root, "");
        return answer;
    }
};