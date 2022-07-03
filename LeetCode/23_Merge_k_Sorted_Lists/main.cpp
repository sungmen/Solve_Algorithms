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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size()) return {};
        map<int, int> m;
        for (int i = 0; i < lists.size(); ++i) {
            for (ListNode* cur = lists[i]; cur != nullptr; cur = cur->next) {
                if (!m[cur->val]) {
                    m[cur->val] = 1;
                } else {
                    m[cur->val]++;
                }
            }
        }
        ListNode* head = new ListNode();
        ListNode* cur = head;
        for (auto it = m.begin(); it != m.end(); ++it) {
            while (it->second --) {
                cur->next = new ListNode(it->first);
                cur = cur->next;
            }
        }
        
        return head -> next;
    }
};