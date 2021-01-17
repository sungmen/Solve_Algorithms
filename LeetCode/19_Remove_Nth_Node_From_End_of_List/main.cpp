/**
* Runtime: 4 ms, faster than 85.83% of C++ online submissions for Remove Nth Node From End of List.
* Memory Usage: 10.7 MB, less than 97.65% of C++ online submissions for Remove Nth Node From End of List.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * tmp = head;
        long long cnt = 0;
        while (tmp != nullptr) {
            tmp = tmp->next;
            cnt++;
        }
        if (n == cnt) return head->next;
        else if (n == 1) {
            tmp = head;
            while (tmp != nullptr) {
                if (cnt == 2) {
                    tmp->next = nullptr;
                }else {
                    tmp = tmp->next;
                }
                cnt--;
            }
            return head;
        } else {
            tmp = head;
            while (tmp != nullptr) {
                if (n + 1 == cnt) {
                    ListNode * con;
                    con = tmp->next->next;
                    tmp->next = nullptr;
                    tmp->next = con;
                    break;
                } else {
                    tmp = tmp->next;
                    cnt--;
                }
            }
            return head;
        }
    }
};