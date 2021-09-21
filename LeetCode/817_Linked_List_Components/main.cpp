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
    int numComponents(ListNode* head, vector<int>& nums) {
        int ans = 0;
        map<int, int> m;
        for (auto n : nums) m[n] = 1;
        bool chk = 0;
        for (ListNode* start = head; start; start = start->next) {
            if (m[start->val] && !chk) {
                chk = 1;
                ++ans;
            } else if (!m[start->val]) {
                chk = 0;
            }
        }
        return ans;
    }
};