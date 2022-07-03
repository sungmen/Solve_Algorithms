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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode * head = list1;
        while(list1->val != a - 1) {
            list1 = list1->next;
        }
        ListNode * next = list1->next;        
        list1->next = list2;
        while(list2->next != nullptr) {
            list2 = list2->next;
        }
        while(next->val != b+1) {
            next = next->next;
        }
        list2->next = next;
        return head;
    }
};