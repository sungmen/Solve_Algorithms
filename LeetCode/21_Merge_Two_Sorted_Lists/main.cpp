/**
* Runtime: 8 ms, faster than 86.79% of C++ online submissions for Merge Two Sorted Lists.
* Memory Usage: 14.6 MB, less than 100.00% of C++ online submissions for Merge Two Sorted Lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        else if (l2 == nullptr) return l1;
        ListNode * head = new ListNode();
        ListNode * start = head;
        while(l1 != nullptr || l2 != nullptr) {
            int res1 = 101, res2 = 101;
            if (l1 != nullptr) {
                res1 = l1->val;
            }
            if (l2 != nullptr) {
                res2 = l2->val;
            }
            if (res1 < res2) {
                start->next = l1;
                start = l1;
                l1 = l1->next;
            } else {
                start->next = l2;
                start = l2;
                l2 = l2->next;
            }
        }
        return head->next;
    }
};