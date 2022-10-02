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
    unordered_map<int, int> um;
    int dfs(TreeNode* root)
    {
        if (nullptr == root)
        {
            return 0;
        }
        int p = root->val + dfs(root->left) + dfs(root->right);
        um[p] ++;
        return p;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) 
    {
        dfs(root);
        int cnt = 0;
        vector<int> res;
        for (auto it = um.begin(); it != um.end(); it++)
        {
            if (it->second > cnt)
            {
                cnt = it->second;
                res.clear();
                res.push_back(it->first);
            } else if (it->second == cnt)
            {
                res.push_back(it->first);
            }
        }
        return res;
    }
};