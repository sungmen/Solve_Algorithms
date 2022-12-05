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
    ListNode* removeNodes(ListNode* head) 
    {
        ListNode* cur = head;
        stack<int> stk;
        while (nullptr != cur)
        {
            while (!stk.empty() && stk.top() < cur->val)
            {
                stk.pop();
            }
            stk.push(cur->val);
            cur = cur->next;
        }
        ListNode* ans = new ListNode(stk.top());
        stk.pop();
        while(!stk.empty())
        {
            ListNode* cur = new ListNode(stk.top());
            stk.pop();
            cur->next = ans;
            ans = cur;
        }
        return ans;
    }
};