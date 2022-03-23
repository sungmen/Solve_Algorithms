class Node {
public:
    string key;
    int val;
    Node* next;
    Node* prev;
    Node() {
        next = nullptr;
        prev = nullptr;
    }
};

// prev<-node->next
// head        tail
// ++            --
class AllOne {
private:
    Node * node = nullptr, * head = nullptr, * tail = nullptr;
    map<string, Node*> m;
public:
    AllOne() {}
    
    void inc(string key) {
        if (node == nullptr) {
            node = new Node();
            node->val = 1;
            node->key = key;
            head = node;
            tail = node;
            m[key] = node;
        } else if (m[key] != nullptr) {
            Node * cur = m[key];
            cur->val += 1;
            while (cur->prev != nullptr && cur->prev->val < cur->val) {
                Node* tmp = cur->prev;
                if (cur->next != nullptr) {
                    cur->next->prev = tmp;
                }
                if (cur->prev->prev != nullptr) {
                    cur->prev->prev->next = cur;
                }
                tmp->next = cur->next;
                cur->prev = tmp->prev;
                tmp->prev = cur;
                cur->next = tmp;
            }
            while(tail->next != nullptr) {
                tail = tail->next;
            }
            while(head->prev != nullptr) {
                head = head->prev;
            }
            m[key] = cur;
        } else {
            Node * newnode = new Node();
            newnode->key = key;
            newnode->val = 1;
            newnode->prev = tail;
            tail->next = newnode;
            tail = newnode;
            m[key] = newnode;
        }
    }
    
    void dec(string key) {
        if (m[key] != nullptr) {
            Node * cur = m[key];
            if (cur->val == 1) {
                if (tail == cur) {
                    if (tail->next != nullptr) tail = tail=tail->next;
                    else if (tail->prev != nullptr) tail = tail=tail->prev;
                }
                if (head == cur) {
                    head = cur->next;
                }
                if (cur->prev != nullptr) {
                    cur->prev->next = cur->next;
                }
                if (cur->next != nullptr) {
                    cur->next->prev = cur->prev;
                }
                m.erase(key);
                cur = nullptr;
            } else {
                cur->val -= 1;
                while (cur->next != nullptr && cur->next->val > cur->val) {
                    Node* tmp = cur->next;
                    if (cur->prev != nullptr) {
                        cur->prev->next = tmp;
                    }
                    if (cur->next->next != nullptr) {
                        cur->next->next->prev = cur;
                    }
                    tmp->prev = cur->prev;
                    cur->next = tmp->next;
                    tmp->next = cur;
                    cur->prev = tmp;
                }
                while(tail->next != nullptr) {
                    tail = tail->next;
                }
                while(head->prev != nullptr) {
                    head = head->prev;
                }
                m[key] = cur;
            }
        }
    }
    
    string getMaxKey() {
        if (head == nullptr) return "";
        else return head->key;
    }
    
    string getMinKey() {
        if (tail == nullptr) return "";
        else return tail->key;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */