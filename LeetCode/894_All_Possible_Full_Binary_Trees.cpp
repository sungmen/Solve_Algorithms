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
    vector<TreeNode*> allPossibleFBT(int n) {
        if (!(n % 2)) return {};
        vector<vector<TreeNode*>> v(n + 1);
        vector<TreeNode*> tmp;
        TreeNode* node = new TreeNode(0);
        tmp.push_back(node);
        v[1] = (tmp);
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= i - 1; j++) {
                for (TreeNode* k : v[j]) {
                    for (TreeNode* l : v[i - j - 1]) {
                        v[i].push_back(new TreeNode(0, k, l));
                    }
                }
            }
        }
        return v[n];
    }
};