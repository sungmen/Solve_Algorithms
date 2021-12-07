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
    ListNode* deleteMiddle(ListNode* head) {
        int dept = 0;
        for (ListNode * start = head; start != nullptr; start = start->next, dept++);
        if (dept == 1) return {};
        ListNode * start = head;
        for (int i = 1; i < dept/2; ++i, start = start->next);
        start->next = start->next->next;
        return head;
    }
};