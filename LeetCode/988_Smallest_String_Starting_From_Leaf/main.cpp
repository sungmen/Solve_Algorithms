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
    string answer = "";
    
    void dfs(string str, TreeNode* root) {
        char t = root->val + 'a';
        str = t + str;
        if (root->left != nullptr) {
            dfs (str, root->left);
        }
        if (root->right != nullptr) {
            dfs (str, root->right);
        }
        if (root->left == nullptr && root->right == nullptr) {
            if (answer == "" || answer > str) {
                answer = str;
            } 
        }
    }
    
    string smallestFromLeaf(TreeNode* root) {
        if (root == nullptr) return "";
        dfs("", root);
        return answer;
    }
};