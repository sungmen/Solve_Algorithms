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
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        vector<vector<int>> ans(n, vector<int>(m, -1));
        int pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int c = 0, r = 0, l = 0;
        for (auto cur = head; cur != nullptr; cur = cur->next)
        {
            ans[c][r] = cur->val;
            int n_c = c + pos[l][0], n_r = r + pos[l][1];
            if (n_c < 0 || n_c >= n || n_r < 0 || n_r >= m || ans[n_c][n_r] != -1)
            {
                l = (l + 1) % 4;
                n_c = c + pos[l][0], n_r = r + pos[l][1];
            }
            c = n_c;
            r = n_r;
        }
        return ans;
    }
};