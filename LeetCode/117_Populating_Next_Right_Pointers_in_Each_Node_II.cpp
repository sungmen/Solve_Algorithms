/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return {};
        Node *cur, *head = root;
        int de = 0;
        queue<pair<Node *, int>> q;
        // queue pair<Node, int>
        // q.fonrt() Node, int
        //  /      \
        // next -> next
        q.push({root, 1});
        while (! q.empty()) {
            Node* node = q.front().first;
            int next = q.front().second;
            q.pop();
            if (de < next) {
                de = next;
                cur = node;
            } else {
                cur->next = node;
                cur = node;
            }
            if (node->left) {
                q.push({node->left, next + 1});
            }
            if (node->right) {
                q.push({node->right, next + 1});
            }
        }
        return head;
    }
};