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
    ListNode* node;
    
    Solution(ListNode* head) 
    {
        node = head;
    }
    
    int getRandom() 
    {
        int answer;
        int cnt = 1;
        
        for (ListNode* n = node; n != nullptr; n = n->next) 
        {
            if (!(rand() % cnt++)) 
            {
                answer = n->val;
            }
        }
        
        return answer;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */