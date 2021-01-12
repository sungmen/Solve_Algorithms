/**
* Runtime: 28 ms
* Memory Usage: 71.7 MB
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int upper = 0;
        ListNode * head = new ListNode();
        ListNode * start = head;
        while (l1 != nullptr || l2 != nullptr) {
            int tmp1 = 0, tmp2 = 0;
            if (l1 != nullptr) {
                tmp1 = l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                tmp2 = l2->val;
                l2 = l2->next;
            }
            int sum = 0;
            if (tmp1 + tmp2 + upper > 9) {
                sum = tmp1 + tmp2 + upper - 10;
                upper = 1;
            } else {
                sum = tmp1 + tmp2 + upper;
                upper = 0;
            }
            ListNode *temp = new ListNode(sum);
            start->next = temp;
            start = temp;
        }
        if (upper) {
            ListNode * temp = new ListNode(1);
            start->next = temp;
        }
        return head->next;
    }
};
