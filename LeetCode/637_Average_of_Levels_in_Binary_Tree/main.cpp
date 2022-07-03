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
    map<int, pair<int, double>> m;
    void inorder(TreeNode* root, int floor) {
        if (m.find(floor) == m.end()) {
            m[floor] = {1, root->val};
        } else {
            m.find(floor)->second.first++;
            m.find(floor)->second.second+=root->val;
        }
        if (root->left != nullptr) inorder(root->left, floor+1);
        if (root->right != nullptr) inorder(root->right, floor+1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        if (root==nullptr) return {};
        inorder(root, 0);
        vector<double> res;
        for (map<int, pair<int, double>>::iterator it = m.begin(); it != m.end(); ++it) {
            res.push_back(it->second.second/it->second.first);
        }
        return res;
    }
};