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
private:
    int ans = 0;

public:

    void dfs(TreeNode* root, int res, int lr)
    {
        if (nullptr == root)
        {
            ans = max(ans, res);
            return;
        }
        dfs(root->left, (2==lr?res+1:0), 1);
        dfs(root->right, (1==lr?res+1:0), 2);
    }

    int longestZigZag(TreeNode* root) 
    {
        dfs(root, 0, 0);
        return ans;
    }
};
