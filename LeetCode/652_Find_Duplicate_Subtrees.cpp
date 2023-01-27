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
    unordered_map<string, int> um;
    vector<TreeNode*> ans;

   string dfs(TreeNode * root)
    {
        if (root == nullptr)
            return "";
        string l = dfs(root->left);
        string r = dfs(root->right);
        string cur = "(" + l + to_string(root->val) + r + ")";
        if (1 == um[cur])
        {
            ans.push_back(root);
        }
        um[cur]++;
        return cur;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        dfs(root);
        
        return ans;
    }
};