/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root==nullptr) return {};
        vector<vector<int>> v;
        queue<Node*> q;
        q.push(root);
        int idx = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                Node* cur = q.front();
                q.pop();
                if (idx > v.size()) {
                    vector<int> tmp;
                    tmp.push_back(cur->val);
                    v.push_back(tmp);
                } else {
                    v[idx-1].push_back(cur->val);
                }
                for (int i = 0; i < cur->children.size(); ++i) {
                    q.push(cur->children[i]);
                }
            }
            idx++;
        }
        return v;
    }
};