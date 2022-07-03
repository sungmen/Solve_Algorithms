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
private:
    vector<int> v;
    
public:
    void dfs(ListNode* head, int idx) 
    {
        v.push_back(head->val);
        
        if (head->next != nullptr) 
        {
            dfs(head->next, idx + 1);
        }
    }
    
    void reorderList(ListNode* head) 
    {
        dfs(head, 0);
        
        int idx = 0;
        int m = v.size() - 1;
        
        while (!(head == nullptr)) 
        {
            head->val = v[idx];
            head = head->next;
            if (head == nullptr) break;
            head->val = v[m - idx++];
            head = head->next;
        }
    }
};