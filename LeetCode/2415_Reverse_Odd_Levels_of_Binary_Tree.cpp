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
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        unordered_map<int, vector<TreeNode*>> m;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while (!q.empty())
        {
            TreeNode* cur = q.front().first;
            int curcnt = q.front().second;
            q.pop();
            
            if (cur->left)
            {
                if (! (curcnt % 2))
                {
                    m[curcnt + 1].push_back(cur->left);
                }
                q.push({cur->left, curcnt + 1});
            }
            
            if (cur->right)
            {
                if (! (curcnt % 2))
                {
                    m[curcnt + 1].push_back(cur->right);
                }
                q.push({cur->right, curcnt + 1});
            }
        }
        
        for (auto it = m.begin(); it != m.end(); it++)
        {
            for (int i = 0; i < it->second.size()/2; i++)
            {
                TreeNode* curnode = it->second[i];
                TreeNode* changenode = it->second[it->second.size() - 1 - i];
                swap(curnode->val, changenode->val);
            }
        }
        
        return root;
    }
};