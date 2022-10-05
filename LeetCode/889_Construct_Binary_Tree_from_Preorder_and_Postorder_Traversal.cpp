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
class Solution 
{
public:
    TreeNode* dfs(vector<int>& pre, vector<int>& post, int &precnt, int &postcnt)
    {
        TreeNode* root = new TreeNode(pre[precnt]);
        ++precnt;
        if (root->val != post[postcnt])
        {
            root->left = dfs(pre, post, precnt, postcnt);
        }
        if (root->val != post[postcnt])
        {
            root->right = dfs(pre, post, precnt, postcnt);
        }
        
        ++postcnt;
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) 
    {
        int precnt = 0, postcnt = 0;
        return dfs(preorder, postorder, precnt, postcnt);
    }
};