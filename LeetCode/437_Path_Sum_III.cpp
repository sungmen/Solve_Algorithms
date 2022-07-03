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
    int ans = 0;
    int target = 0;
    
    void dfs(TreeNode* root, vector<int> v)
    {
        if (root == nullptr) return;
        v.push_back(root->val);
        
        dfs(root->left, v);
        dfs(root->right, v);
        
        long long sum = 0;
        for (int i = v.size() - 1; i >= 0; --i)
        {
            sum += v[i];
            
            if (sum == target)
            {
                ++ans;
            }
        }
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        
        target = targetSum;
        
        dfs(root, {});
        
        return ans;
    }
};