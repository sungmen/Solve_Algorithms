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
class Solution 
{
public:
    TreeNode* sortedListToBST(ListNode* head, ListNode* last = nullptr)
    {
        if (head == last) 
        {
            return nullptr;
        }
        ListNode *root = head;
        ListNode *rootNext = head;
        while (rootNext != last && rootNext->next != last)
        {
            root = root->next;
            rootNext = rootNext->next->next;
        }

        TreeNode *r = new TreeNode(root->val);
        r->left = sortedListToBST(head, root);
        r->right = sortedListToBST(root->next, last);
        return r;
    }
};