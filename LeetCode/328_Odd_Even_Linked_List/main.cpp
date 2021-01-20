/**
* Runtime: 16 ms, faster than 74.62% of C++ online submissions for Odd Even Linked List.
* Memory Usage: 11.1 MB, less than 26.11% of C++ online submissions for Odd Even Linked List.
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
    ListNode* oddEvenList(ListNode* head) {
        if (head==nullptr || head->next==nullptr || head->next->next==nullptr) return head;
        ListNode * odd = new ListNode(head->val), * even = new ListNode(head->next->val);
        ListNode * tmp = head->next->next, * tmp_odd = odd, * tmp_even = even;
        while (1) {
            ListNode * tmpNode = new ListNode(tmp->val);
            tmp_odd->next = tmpNode;
            tmp_odd = tmp_odd->next;
            tmp = tmp->next;
            if (tmp == nullptr) break;
            tmpNode = new ListNode(tmp->val);
            tmp_even->next = tmpNode;
            tmp_even = tmp_even->next;
            tmp_even->next = nullptr;
            tmp = tmp->next;
            if (tmp == nullptr) break; 
        }
        tmp_odd->next = even;
        return odd;
    }
};