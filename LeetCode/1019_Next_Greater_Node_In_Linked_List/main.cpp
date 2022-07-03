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
    vector<int> nextLargerNodes(ListNode* head) {
        if (head->next == nullptr) {
            return {0};
        }
        stack<pair<int, int>> stk;
        stk.push({0, head->val});
        head = head->next;
        ListNode * start = head;
        int cnt = 1;
        while (head != nullptr) {
            ++cnt;
            head = head->next;
        }
        vector<int> res(cnt, 0);
        int n = 1;
        while (start != nullptr) {
            if (stk.top().second < start->val) {
                while (!stk.empty() && stk.top().second < start->val) {
                    res[stk.top().first] = start->val;
                    stk.pop();
                }
            }
            stk.push({n, start->val});
            ++n;
            start = start->next;
        }
        return res;
    }
};