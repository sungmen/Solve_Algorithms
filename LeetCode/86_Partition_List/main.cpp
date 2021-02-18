/**
* Runtime: 4 ms, faster than 93.01% of C++ online submissions for Partition List.
* Memory Usage: 10.3 MB, less than 51.56% of C++ online submissions for Partition List.
*/
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
    ListNode* partition(ListNode* head, int x) {
        ListNode * less = new ListNode();
        ListNode * greater = new ListNode();
        ListNode * start = less;
        ListNode * g_start = greater;
        while (head != nullptr) {
            ListNode * tmp = new ListNode(head->val);
            if (head->val < x) {
                less->next = tmp;
                less = less->next;
            } else {
                greater->next = tmp;
                greater = greater->next;
            }
            head = head->next;
        }
        less->next = g_start->next;
        return start->next;
    }
};