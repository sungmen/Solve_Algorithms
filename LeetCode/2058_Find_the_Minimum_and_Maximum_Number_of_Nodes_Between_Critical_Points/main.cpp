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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> answer(2, -1);
        if (head == nullptr) return answer;
        int back = head->val;
        vector<int> tmp;
        int idx = 1;
        if (head->next == nullptr) return answer;
        head = head->next;
        while (head->next != nullptr) {
            if ((back < head->val && head->val > head->next->val) || (back > head->val && head->val < head->next->val)) {
                tmp.push_back(idx);
                if (tmp.size() > 1) {
                    if (answer[0] != -1) {
                        answer[0] = min(answer[0], tmp.back() - tmp[tmp.size()-2]);
                    } else {
                        answer[0] = tmp.back() - tmp[tmp.size()-2];
                    }
                    answer[1] = tmp.back() - tmp[0];
                }
            }
            idx++;
            back = head->val;
            head = head->next;
        }
        return answer;
    }
};