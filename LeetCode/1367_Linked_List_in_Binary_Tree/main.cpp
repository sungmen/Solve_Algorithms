/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    bool answer = false;
    
    void compare(ListNode* head, TreeNode* root) {
        if (head->next == nullptr) {
            answer = true;
            return;
        }
        if (root->left != nullptr && root->left->val == head->next->val) {
            compare(head->next, root->left);
        }
        if (root->right != nullptr && root->right->val == head->next->val) {
            compare(head->next, root->right);
        }
        
    }
    
    void findStart(ListNode* head, TreeNode* root) {
        if (head->val == root->val) {
            compare(head, root);
        }
        if (root->left != nullptr) {
            findStart(head, root->left);
        }
        if (root->right != nullptr) {
            findStart(head, root->right);
        }
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        findStart(head, root);
        return answer;
    }
};