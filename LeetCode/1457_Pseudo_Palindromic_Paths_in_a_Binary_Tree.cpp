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
    int answer = 0;
    
    void dfs(TreeNode* root, vector<int> m, int odd)
    {
        if ((++m[root->val]) % 2)
        {
            odd++;
        }
        else
        {
            odd--;
        }
        if (root->left)
        {
            dfs(root->left, m, odd);
        }
        if (root->right)
        {
            dfs(root->right, m, odd);
        }
        if (!root->left && !root->right && (1 == odd || 0 == odd))
        {
            ++answer;
        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) 
    {
        vector<int> arr(10, 0);
        dfs(root, arr, 0);
        return answer;
    }
};