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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode * result = new ListNode();
        while(head != nullptr) {
            ListNode * tmp = new ListNode();
            tmp->val = head->val;
            head = head->next;
            ListNode * tmp2;
            tmp2 = result->next;
            tmp->next = tmp2;
            result->next = tmp;
        }
        return result->next;
    }
};