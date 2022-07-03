/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* result;
    
public:
    void dfs(Node* head) {
        result->next = new Node(head->val);
        result->next->prev = result;
        result = result->next;
        if (head->child != nullptr) {
            dfs(head->child);
        }
        if (head->next != nullptr) {
            dfs(head->next);
        }
        
    }
    
    Node* flatten(Node* head) {
        if (head == nullptr) return head;
        result = new Node(head->val);
        Node *resHead = result;
        if (head->child != nullptr) {
            dfs(head->child);
        }
        if (head->next != nullptr) {
            dfs(head->next);
        }
        return resHead;
    }
};