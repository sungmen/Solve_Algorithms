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
class FindElements 
{
public:
    map<int, int> m;
        
    FindElements(TreeNode* root) 
    {
        dfs(root, 0);       
    }
    
    void dfs(TreeNode* root, int idx)
    {
        m[idx] = 1;
        if (root->left)
        {
            dfs(root->left, idx*2 + 1);
        }
        if (root->right)
        {
            dfs(root->right, idx*2 + 2);
        }
    }
    
    bool find(int target) 
    {
        return m[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */