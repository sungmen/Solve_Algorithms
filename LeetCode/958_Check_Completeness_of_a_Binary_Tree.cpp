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
    bool isCompleteTree(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        bool chk = 1;
        
        while (!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();
            if (! cur)
            {
                chk = 0;
            }
            else
            {
                if (! chk)
                {
                    return 0;
                }
                q.push(cur->left);
                q.push(cur->right);
            }
            
        }
        
        return 1;
    }
};