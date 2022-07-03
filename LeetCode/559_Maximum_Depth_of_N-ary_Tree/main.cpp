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
private:
    int res = 0;
public:
    void dfs(Node* root, int floor) {
        if (floor > res) {
            res = floor;
        }
        
        for (int i = 0; i < root->children.size(); i++) {
            dfs(root->children[i], floor + 1);
        }
    }
    
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        dfs(root, 1);
        
        return res;
    }
};