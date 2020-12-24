/**
 * Runtime: 4 ms, faster than 57.12% of C++ online submissions for Swap Nodes in Pairs.
 * Memory Usage: 8.1 MB, less than 36.65% of C++ online submissions for Swap Nodes in Pairs.
 * /

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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return head;
        ListNode * cur_node = head;
        while (cur_node->next != nullptr) {
            int t = cur_node->val;
            ListNode* next_node = cur_node->next;
            cur_node->val = next_node->val;
            next_node->val = t;
            if(next_node->next == nullptr) return head;
            cur_node = next_node->next;
        }
        return head;
    }
};