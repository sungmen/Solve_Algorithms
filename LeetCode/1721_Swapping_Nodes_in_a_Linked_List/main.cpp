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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode * tmp = head;
        int len = 1;
        ListNode * swap_n1;
        while(tmp != nullptr) {
            if (len == k) swap_n1 = tmp;
            tmp = tmp->next;
            len++;
        }
        len--;
        tmp = head;
        int swap_len = len - k;
        len = 0;
        ListNode * swap_n2;
        while(tmp != nullptr) {
            if (len == swap_len) {
                swap_n2 = tmp;
                break;
            }
            tmp = tmp->next;
            len++;
        }
        int tmp_n = swap_n1->val;
        int tmp_n2 = swap_n2->val;
        swap_n1->val = tmp_n2;
        swap_n2->val = tmp_n;
        return head;
    }
};