/**
* Runtime: 460 ms, faster than 97.40% of C++ online submissions for Find a Corresponding Node of a Binary Tree in a Clone of That Tree.
* Memory Usage: 163.8 MB, less than 97.22% of C++ online submissions for Find a Corresponding Node of a Binary Tree in a Clone of That Tree.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode * result;
    
    void searchTargetNode(TreeNode* cloned, TreeNode* target) {
        if (target->val == cloned->val) {
            result = cloned;
            return;
        } else {
            if (cloned->left != NULL) {
                searchTargetNode(cloned->left, target);
            }
            if (cloned->right != NULL) {
                searchTargetNode(cloned->right, target);
            }
        }
        return;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        searchTargetNode(cloned, target);
        return result;
    }
};