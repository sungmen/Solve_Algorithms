/**
* Runtime: 8 ms, faster than 85.45% of C++ online submissions for Rotate List.
* Memory Usage: 12.2 MB, less than 21.04% of C++ online submissions for Rotate List.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;
        if(head->next == nullptr) return head;
        ListNode* start;
        start = head;
        ListNode* end;
        ListNode* endback;
        int cnt = 1;
        while(head->next != nullptr) {
            cnt++;
            head = head->next;
        }
        for (int i = 0; i < k%cnt; i++) {
            ListNode* temp = start;
            while(temp->next != nullptr) {
                endback = temp;
                temp = temp->next;
            }
            end = temp;
            endback->next = nullptr;
            end->next = start;
            start = end;
        }
        return start;
    }
};
