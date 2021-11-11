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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        ListNode* start = nullptr;
        ListNode* back = head;
        int idx = 1;
        ListNode* tmp;
        ListNode* curtmp;
        for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
            tmp = new ListNode(cur->val);
            if (idx == 1) {
                start = tmp;
                curtmp = start;
            } else {
                tmp->next = curtmp;
                curtmp = tmp;
            }
            if (idx == k) {
                back->next = curtmp;
                start->next = cur->next;
                back = start;
                idx = 1;
            } else {
                idx++;
            }
        }
        return head -> next;
    }
};