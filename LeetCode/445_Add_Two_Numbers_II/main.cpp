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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string a = "", b = "";
        while (l1 != NULL) {
            a += l1->val + '0';
            l1 = l1->next;
        }
        while (l2 != NULL) {
            b += l2->val + '0';
            l2 = l2->next;
        }
        int upper = 0;
        int l = a.size() - 1, r = b.size() - 1;
        string str = "";
        while(l >= 0 && r >= 0) {
            int tmp = (a[l--] - '0') + (b[r--] - '0') + upper;
            upper = tmp / 10;
            tmp %= 10;
            char t = tmp + '0';
            str = t + str;
        }
        while(l >= 0) {
            int tmp = (a[l--] - '0') + upper;
            upper = tmp / 10;
            tmp %= 10;  
            char t = tmp + '0';
            str = t + str;
        }
        while(r >= 0) {
            int tmp = (b[r--] - '0') + upper;
            upper = tmp / 10;
            tmp %= 10;  
            char t = tmp + '0';
            str = t + str;
        }
        if (upper) str = '1' + str;
        int i = 0;
        ListNode* res = new ListNode(str[i++] - '0'), *head = res;
        while (i < str.size()) {
            ListNode* tmp = new ListNode(str[i++] - '0');
            res->next = tmp;
            res = res->next;
        }
        return head;
    }
};