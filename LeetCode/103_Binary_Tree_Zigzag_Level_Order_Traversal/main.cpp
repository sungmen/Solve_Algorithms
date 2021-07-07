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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        stack<pair<TreeNode*, int>> stk, stk2;
        stk.push({root, 0});
        vector<vector<int>> v;
        while (!stk.empty()) {
            while(!stk.empty()) {
                pair<TreeNode*, int> cur = stk.top();
                stk.pop();
                int value = cur.first->val;
                if (cur.second+1 > v.size()) {
                    v.push_back({value});
                } else {
                    v[cur.second].push_back(value);
                }
                if (cur.first->left != nullptr) {
                    stk2.push({cur.first->left, cur.second+1});
                }    
                if (cur.first->right != nullptr) {
                    stk2.push({cur.first->right, cur.second+1});
                }  
            }
            while(!stk2.empty()) {
                pair<TreeNode*, int> cur = stk2.top();
                stk2.pop();
                int value = cur.first->val;
                if (cur.second+1 > v.size()) {
                    v.push_back({value});
                } else {
                    v[cur.second].push_back(value);
                }
                if (cur.first->right != nullptr) {
                    stk.push({cur.first->right, cur.second+1});
                }
                if (cur.first->left != nullptr) {
                    stk.push({cur.first->left, cur.second+1});
                }      
            }
        }
        return v;
    }
};