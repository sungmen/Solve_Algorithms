/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    map<int, vector<int>> m;
    void findTree(TreeNode* root)
    {
        int cur = root->val;
        if (root->left)
        {
            int l = root->left->val;
            m[cur].push_back(l);
            m[l].push_back(cur);
            findTree(root->left);
        }
        if (root->right)
        {
            int r = root->right->val;
            m[cur].push_back(r);
            m[r].push_back(cur);
            findTree(root->right);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        findTree(root);
        queue<int> q;
        bool chk[501];
        memset(chk, 0, sizeof(chk));
        q.push(target->val);
        chk[target->val] = 1;
        while (k-- && !q.empty())
        {
            int si = q.size();
            while(si--)
            {
                int cur = q.front();
                q.pop();
                vector<int> curVec = m[cur];
                for (auto c : curVec)
                {
                    if (chk[c]) continue;
                    chk[c] = 1;
                    q.push(c);
                }
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};