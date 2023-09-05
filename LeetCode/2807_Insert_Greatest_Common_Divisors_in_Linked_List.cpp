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
class Solution 
{
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
        if (head->next == nullptr) return head;
        ListNode* cur = head;
        for (ListNode* it = head-> next; it != nullptr; it = it->next)
        {
            int a = cur->val;
            int b = it->val;
            int gcdnum = __gcd(a, b);
            ListNode* next = new ListNode(gcdnum, it);
            cur->next = next;
            if (cur->next != nullptr) cur = cur->next;
            if (cur->next != nullptr) cur = cur->next;
        }
        return head;    
    }
};