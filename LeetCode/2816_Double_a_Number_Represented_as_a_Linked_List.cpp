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
    ListNode* doubleIt(ListNode* head) 
    {
        int s = head->val;
        s *= 2;
        ListNode* first = new ListNode(0);
        if (s >= 10)
        {
            first->val = 1;
        }
        for (ListNode * cur = head; cur != nullptr; cur = cur->next)
        {
            int t = 0;
            if (cur->next != nullptr)
            {
                int p = cur->next->val;
                if (p * 2>= 10)
                    t = 1;
            }
            int c = cur->val;
            c *= 2;
            c += t;
            c %= 10;
            cur->val = c;
        }
        if (first->val == 1)
        {
            first->next = head;
            head = first;
        }
        return head;
    }

};