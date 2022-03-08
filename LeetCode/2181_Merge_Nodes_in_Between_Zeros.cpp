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
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode * cur = new ListNode(head->val), * list = cur;
        head = head->next;
        while (head && head->next) {
            if (!head->val) {
                cur->next = new ListNode(head->val);
                cur = cur->next;
            } else {
                cur->val += head->val;
            }
            head = head->next;
        }
        return list;
    }
};