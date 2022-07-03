/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        ListNode *startA = headA, *startB = headB;
        while(headA != NULL && headB != NULL && headA != headB) {
            headA = headA->next;
            headB = headB->next;
            if (headA == headB) return headA;
            if (headA == NULL) headA = startB;
            if (headB == NULL) headB = startA;
        }
        return headA;
    }
};