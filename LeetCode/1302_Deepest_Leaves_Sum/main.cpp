/**
* Runtime: 44 ms, faster than 74.92% of C++ online submissions for Deepest Leaves Sum.
* Memory Usage: 38 MB, less than 94.45% of C++ online submissions for Deepest Leaves Sum.
*/
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
    int MAX = 0;
    int res = 0;
    
    void deepestNode(TreeNode* root, int deep) {
        if (deep > MAX) {
            MAX = deep;
            res = root->val;
        } else if (deep == MAX) {
            res += root->val;
        }
        if (root->left != nullptr) {
            deepestNode(root->left, deep + 1);
        }
        if (root->right != nullptr) {
            deepestNode(root->right, deep + 1);
        }
    }
    
    int deepestLeavesSum(TreeNode* root) {
        deepestNode(root, 0);
        return res;
    }
};