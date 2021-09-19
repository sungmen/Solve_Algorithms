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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k);
        vector<ListNode*> start(k);
        ListNode* startNode = head;
        int cnt = 0;
        while (startNode != nullptr) {
            startNode = startNode->next;
            ++cnt;
        }
        int t = cnt / k, c = cnt % k, index = 0;
        while (k) {
            int tmp = t;
            while(tmp--) {
                if (res[index] == nullptr) {
                    res[index] = new ListNode(head->val);
                    start[index] = res[index];
                } else {
                    ListNode * next = new ListNode(head->val);
                    res[index]->next = next;
                    res[index] = res[index]->next;
                }
                head = head->next;
            }
            if (c) {
                if (res[index] == nullptr) {
                    res[index] = new ListNode(head->val);
                    start[index] = res[index];
                } else {
                    ListNode * next = new ListNode(head->val);
                    res[index]->next = next;
                    res[index] = res[index]->next;
                }   
                head = head->next;             
                --c;
            }
            ++index;
            --k;
        }
        return start;
    }
};