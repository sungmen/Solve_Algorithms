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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if (head->next == nullptr) return head;
        int idx = 2, cnt = 1;
        ListNode* back = head;
        ListNode* first;
        ListNode* tmp;
        for (ListNode* start = head->next; start != nullptr; start = start->next) {
            if (cnt == 1) {
                first = new ListNode(start->val);
                tmp = first;
            } else {
                ListNode* tmpStart = new ListNode(start->val, tmp);
                tmp = tmpStart;
            }
            if (idx == cnt) {
                if (!(idx % 2)) {
                    back->next = tmp;
                    first->next = start->next;
                    back = first;
                } else {
                    back = start;
                }
                idx++;
                cnt = 1;
            } else {
                cnt++;
            }
        }
        if (cnt % 2 && cnt != 1) {
            back->next = tmp;
        }
        return head;
    }
};