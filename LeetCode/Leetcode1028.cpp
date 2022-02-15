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
    TreeNode* recover(string traversal, int cnt) {
        int num = 0, i = 0, n = traversal.size();
        string str1 = "";
        string str2 = "";
        while (i < n && traversal[i] != '-') {
            num *= 10;
            num += (traversal[i++]-'0');
        }
        int c = 0;
        int l = 0, s = 0;
        int chk = 0;
        while (i < n && traversal[i++]=='-') {
            chk=1;
        }
        TreeNode* node = new TreeNode(num);
        if (!chk) {
            return node;
        }
        l = i - 1;
        while (i < n) {
            if (traversal[i++]=='-') {
                c++;
            } else {
                if (c == cnt) {
                    str1 = traversal.substr(l, i-cnt-1-l);
                    l = i;
                }
                c = 0;
            }
        }
        if (str1 == "") {
            str1 = traversal.substr(l);    
        } else {
            str2 = traversal.substr(l-1);
        }
        if (str1 != "") {
            node->left = recover(str1, cnt + 1);
        }
        if (str2 != "") {
            node->right = recover(str2, cnt + 1);
        }
        return node;
    }
    
    TreeNode* recoverFromPreorder(string traversal) {
        return recover(traversal, 1);
    }
};