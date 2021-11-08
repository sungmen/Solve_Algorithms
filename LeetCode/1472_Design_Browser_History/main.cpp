class Node {    
public:
    string page;
    Node* next;
    Node* nback;
    
    Node() {
        page = "";
        next = nullptr;
        nback = nullptr;
    }
    Node(string page) {
        this->page = page;
        next = nullptr;
        nback = nullptr;
    }    
};

class BrowserHistory {
private:
    Node* node;
public:
    BrowserHistory(string homepage) {
        node = new Node(homepage);
    }
    
    void visit(string url) {
        Node* nvisit = new Node(url);
        node->next = nvisit;
        nvisit->nback = node;
        node = node->next;
    }
    
    string back(int steps) {
        while (steps && node->nback != nullptr) {
            node = node->nback;
            --steps;
        }
        return node->page;
    }
    
    string forward(int steps) {
        while (steps && node->next != nullptr) {
            node = node->next;
            --steps;
        }
        return node->page;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */