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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* cur = new ListNode(head->val);
        head = head->next;
        while (head != nullptr) {
            ListNode* start = cur;
            ListNode* insertnode = new ListNode(head->val);
            if (head->val < start->val) {
                insertnode->next = start;
                cur = insertnode;
            } else {
                bool chk = false;
                ListNode* c;
                for (c = start; c->next != nullptr; c = c->next) {
                    if (c->next->val > head->val) {
                        ListNode* tmpc = c->next;
                        c->next = insertnode;
                        insertnode->next = tmpc;                        
                        chk = 1;
                        break;
                    }
                }
                if (!chk) {
                    c->next = insertnode;
                }
            }            
            head = head->next;
        }        
        return cur;
    }
};