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
    unordered_map<int, vector<pair<int, int>>> m;
    unordered_map<int, int> r;
    unordered_map<int, int> t;
    
    void dfs(TreeNode& root, int idx)
    {
        for (auto i : m[idx])
        {
            if (i.second == 1)
            {
                root.left = new TreeNode(i.first);
                dfs(*root.left, i.first);
            }
            else
            {
                root.right = new TreeNode(i.first);
                dfs(*root.right, i.first);
            }
        }
    }
    
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
    {
        for (auto descript : descriptions)
        {
            r[descript[0]] = 1;
            t[descript[1]] = 1;
            m[descript[0]].push_back({descript[1], descript[2]});
        }
        int start = 0;
        for (auto it = r.begin(); it != r.end(); it++)
        {
            if (t.find(it->first) == t.end())
            {
                start = it->first;
                break;
            }
        }
        TreeNode* root = new TreeNode(start);
        dfs (* root, start);
        
        return root;
    }
};