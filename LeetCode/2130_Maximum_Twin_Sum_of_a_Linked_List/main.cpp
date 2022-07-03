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
    int pairSum(ListNode* head) {
        vector<int> p;
        for (ListNode* s = head; s != nullptr; p.push_back(s->val), s = s->next);
        int l = 0, r = p.size()-1, res = 0;
        while (l < r) {
            res = max(res, p[l++] + p[r--]);
        }
        return res;
    }
};