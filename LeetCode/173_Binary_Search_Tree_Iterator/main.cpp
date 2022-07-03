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
class BSTIterator {
public:
    vector<int> v;
    int idx = 0;
    
    void dfs(TreeNode* root) {
        if (root->left != nullptr) {
            dfs(root->left);
        }
        
        if (root != nullptr) {
            v.push_back(root->val);
        }
        
        if (root->right != nullptr) {
            dfs(root->right);
        }        
    }
    
    BSTIterator(TreeNode* root) {
        dfs(root);
    }
    
    int next() {
        return v[idx++];
    }
    
    bool hasNext() {
        if (idx < v.size()) {
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */