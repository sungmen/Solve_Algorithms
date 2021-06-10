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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        vector<int> v(right-left+1);
        int t = right-left;
        ListNode* start = head, * mid1 = start, * mid2 = start;
        int i = 1;
        
        if (left == right) return head;
        
        while(start != nullptr) 
        {
            if (i + 1 == left) 
            {
                mid1 = start;
            }
            else if (i - 1 == right) 
            {
                mid2 = start;
            }
            else if (i >= left && i <= right) 
            {
                v[t+left-i] = start->val;
            }
            
            start = start->next;
            i++;
        }
        
        ListNode * tmp = new ListNode();
        ListNode * tmpHead = tmp;
        
        for (auto vv : v) 
        {
            ListNode* tmpp = new ListNode(vv);
            tmp->next = tmpp;
            tmp = tmp->next;
        }
        
        tmpHead = tmpHead->next;
        
        if (left != 1) 
        {
            mid1->next = tmpHead;
        } 
        else 
        {
            head = tmpHead;
        }
        
        if (right != i-1) 
        {
            tmp->next = mid2;
        }
        
        return head;
    }
};