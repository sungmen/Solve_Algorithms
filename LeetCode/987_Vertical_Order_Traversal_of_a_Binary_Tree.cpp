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
    map<int, priority_queue<pair<int, int>>> m;
    priority_queue<pair<int, int>> pq;
    
    void dfs(TreeNode* t, int n, int deep)
    {
        if (nullptr == t)
        {
            return;
        }
        m[n].push({-deep, -(t->val)});
        dfs(t->left, n - 1, deep+1);
        dfs(t->right, n + 1, deep+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        dfs(root, 0, 0);
        
        vector<vector<int>> res;
        
        for (auto it = m.begin(); it != m.end(); it++)
        {
            vector<int> vpq;
            while (!it->second.empty())
            {
                vpq.push_back(-(it->second.top().second));
                it->second.pop();
            }
            res.push_back(vpq);
        }
        
        return res;
    }
};