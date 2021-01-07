/**
* Runtime: 20 ms, faster than 10.78% of C++ online submissions for Remove Duplicates from Sorted List II.
* Memory Usage: 12 MB, less than 10.69% of C++ online submissions for Remove Duplicates from Sorted List II.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        vector<int> v(201, 0);
        while(head->next != nullptr) {
            v[head->val + 100]++;
            head = head->next;
        }
        v[head->val + 100]++;
        ListNode *header = new ListNode();
        ListNode *cur;
        ListNode *start;
        cur = header;
        start = cur;
        for (int i = 0; i <= 200; i++) {
            if (v[i] == 1) {
                ListNode *next = new ListNode(i-100);
                cur->next = next;
                cur = next;
            }
        }
        return start->next;
    }
};