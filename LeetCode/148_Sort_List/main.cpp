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
private:
    vector<int> v;
    
public:
    void setList(ListNode* head) {
        if (head != nullptr) {
            v.push_back(head->val);
            setList(head->next);
        }    
    }
    
    ListNode* sortList(ListNode* head) {
        setList(head);
        sort(v.begin(), v.end());
        ListNode* start = head;
        int idx = 0;
        while (start != nullptr) {
            start->val = v[idx++];
            start = start->next;
        }
        return head;
    }
};