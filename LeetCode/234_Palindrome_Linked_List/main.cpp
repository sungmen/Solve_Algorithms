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
    bool isPalindrome(ListNode* head) {
        string str = "";
        while(head != nullptr) {
            str += (head->val + '0');
            head = head->next;
        }
        int len = str.size()/2;
        string rev = str.substr(0, len);
        string s = str.substr(str.size()-len, len);
        reverse(rev.begin(), rev.end());
        return (rev.compare(s)?false:true);
    }
};