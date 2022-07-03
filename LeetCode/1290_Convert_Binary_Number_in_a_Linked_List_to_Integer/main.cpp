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
    int getDecimalValue(ListNode* head) {
        string str = "";
        while(head != nullptr) {
            str += (head->val+'0');
            head = head->next;
        }
        int num = 0, val = 1;        
        for (int i = str.size()-1; i >= 0; i--) {
            num += (str[i]-'0') * val;
            val *= 2;
        }
        return num;
    }
};