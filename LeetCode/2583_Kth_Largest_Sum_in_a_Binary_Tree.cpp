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
class Solution {
public:
    void dfs(int depth, TreeNode* root, vector<long long>& v)
    {
        if (root == nullptr) return;
        if (depth == v.size())
        {
            v.push_back(root->val);
        }
        else
        {
            v[depth] += root->val;
        }
        dfs(depth + 1, root->left, v);
        dfs(depth + 1, root->right, v);
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> v;    
        dfs(0, root, v);
        sort(v.begin(), v.end());
        return (k <= v.size()) ? v[v.size() - k] : -1;
    }
};