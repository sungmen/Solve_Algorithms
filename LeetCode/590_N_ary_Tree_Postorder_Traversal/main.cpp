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

class Solution 
{
public:
    vector<int> answer;
    
    void dfs(Node* root) 
    {
        for (auto child : root->children) 
        {
            dfs(child);
        }
        answer.push_back(root->val);
    }
    
    vector<int> postorder(Node* root) 
    {
        if (root == nullptr) return {};
        
        dfs(root);
        
        return answer;
    }
};