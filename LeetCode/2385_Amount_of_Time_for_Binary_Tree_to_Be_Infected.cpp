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
    map<int, vector<int>> m;
    
    void findAll(TreeNode* root)
    {
        int cur = root->val, l, r;

        if (root->left)
        {
            l = root->left->val;
            m[cur].push_back(l);
            m[l].push_back(cur);
            findAll(root->left);
        }
        if (root->right)
        {
            r = root->right->val;
            m[cur].push_back(r);
            m[r].push_back(cur);
            findAll(root->right);
        }
    }

    int amountOfTime(TreeNode* root, int start) 
    {
        findAll(root);
        int ans = 0;
        bool chk[100001];
        memset(chk, 0, sizeof(chk));
        queue<int> q;
        q.push(start);
        chk[start] = 1;
        while (!q.empty())
        {
            int si = q.size();
            while (si--)
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
            ans++;
        }
        return ans - 1;        
    }
};