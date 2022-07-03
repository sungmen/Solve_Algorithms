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
    vector<int> tmp;
    void dfs(TreeNode* root, int depth) 
    {
        if (depth == tmp.size())
        {
            tmp.push_back(root->val);
        }
        
        if (root->right) 
        {
            dfs(root->right, depth + 1);
        }
        if (root->left)
        {
            dfs(root->left, depth + 1);
        }
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        if (root == nullptr) return {};
        
        dfs(root, 0);
        
        return tmp;
    }
};