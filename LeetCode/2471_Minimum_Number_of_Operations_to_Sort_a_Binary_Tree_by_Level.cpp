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
    int minimumOperations(TreeNode* root) 
    {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int si = q.size();
            vector<int> v;
            while (si--)
            {
                TreeNode* cur = q.front();
                q.pop();
                if (cur == nullptr) continue;
                v.push_back(cur->val);
                q.push(cur->left);
                q.push(cur->right);
            }
            vector<pair<int, int>> p;
            for (int i = 0; i < v.size(); i++)
            {
                p.push_back({v[i], i});
            }
            sort(p.begin(), p.end());
            for (int i = 0; i < v.size(); i++)
            {
                while (p[i].second != i)
                {
                    swap(p[i], p[p[i].second]);
                    ans++;
                }
            }
        }
        return ans;
    }
};