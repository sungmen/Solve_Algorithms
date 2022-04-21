/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        map<Node*, int> m;
        vector<pair<Node*, Node*>> v;
        Node* cur = head;
        int cnt = 0;
        while (cur != nullptr) {
            v.push_back({cur, new Node(cur->val)});
            m[cur] = cnt;
            cnt++;
            cur = cur->next;
        }
        int si = v.size();
        for (int i = 0; i < si; i++) {
            if (i != si-1) v[i].second->next = v[i+1].second;
            if (v[i].first->random == nullptr) v[i].second->random = nullptr;
            else v[i].second->random = v[m[v[i].first->random]].second;
        }
        v[si-1].second->next = nullptr;
        return v[0].second;
    }
};