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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* head = new TreeNode(preorder[0]);
        TreeNode* start = head;
        for (int i = 1; i < preorder.size(); ++i) {
            head = start;
            while (1) {
                if (head->val < preorder[i]) {
                    if (head->right != nullptr) {
                        head = head->right;
                    } else {
                        head->right = new TreeNode(preorder[i]);
                        break;
                    }
                } else {
                    if (head->left != nullptr) {
                        head = head->left;
                    } else {
                        head->left = new TreeNode(preorder[i]);
                        break;
                    }
                }
            }
        }
        return start;
    }
};