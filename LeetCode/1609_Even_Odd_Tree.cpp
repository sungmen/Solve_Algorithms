/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        vector<vector<int>> v;
        queue<pair<TreeNode*,int>> q;
        q.push({root, 1});
        // v is vector for treNode tree
        while (! q.empty()) {
            TreeNode* cur = q.front().first;
            int deep = q.front().second;
            q.pop();
            if (deep > v.size()) {
                vector<int> tmp;
                tmp.push_back(cur->val);
                v.push_back(tmp);
            } else {
                v[deep-1].push_back(cur->val);
            }
            if (cur->left) {
                q.push({cur->left, deep + 1});
            }
            if (cur->right) {
                q.push({cur->right, deep + 1});
            }
        }
        // find odd, even
        for (int i = 0; i < v.size(); i++) {
            int back = v[i][0];
            if (!(i%2)) {
                // check if level is even, back is even return false;
                if (!(back%2)) return false;
            } else {
                if (back%2) return false;
            }
            for (int j = 1; j < v[i].size(); j++) {
                if (!(i%2)) {
                    if (!(v[i][j]%2) || back >= v[i][j]) return false;
                } else {
                    if (v[i][j]%2 || back <= v[i][j]) return false;
                }
                back = v[i][j];
            }
        }
        return true;
    }
};