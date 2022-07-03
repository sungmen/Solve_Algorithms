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
private:
    vector<int> v;
    int MAX = 0;
    
public:
    void dfs(TreeNode* root, int cnt) 
    {
        if(cnt == v.size()) 
        {
            v.push_back(root->val);
        } 
        else 
        {
            if (v[cnt] < root->val) 
            {
                v[cnt] = root->val;
            }
        }
        
        if (root->left != NULL) 
        {
            dfs(root->left, cnt + 1);
        }
        
        if (root->right != NULL)
        {
            dfs(root->right, cnt + 1);
        }
    }
    
    vector<int> largestValues(TreeNode* root) 
    {
        if (root == NULL) return {};
        
        dfs(root, 0);
        
        return v;
    }
};