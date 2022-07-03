class Node {
public:
    int val;
    Node* next = nullptr;
    Node* back = nullptr;
    Node(){}
    Node(int val) {
        this->val = val;
    }
};

class FrontMiddleBackQueue {
public:
    Node* front = nullptr, *tail = nullptr, *middle = nullptr;
    int size = 0;
    
    FrontMiddleBackQueue() {}
    
    void pushFront(int val) {
        if (front == nullptr) {
            front = new Node(val);
            tail = front;
            middle = tail;
        } else {
            Node * tmp = new Node(val);
            front->back = tmp;
            tmp->next = front;
            front = tmp;
            if (size % 2) {
                middle = middle->back;
            }
        }
        size++;
    }
    
    void pushMiddle(int val) {
        Node *tmp = new Node(val);
        if (middle == nullptr) {
            front = new Node(val);
            tail = front;
            middle = tail;
        } else if (size == 1) {
            middle = tmp;
            front = tmp;
            middle->next = tail;
            tail->back = middle;
        } else if (size % 2) {
            tmp->next = middle;
            tmp->back = middle->back;
            middle->back->next = tmp;
            middle->back = tmp;
            middle = tmp;
        } else {
            tmp->next = middle->next;
            tmp->back = middle;
            middle->next->back = tmp;
            middle->next = tmp;
            middle = tmp;
        }
        size++;
    }
    
    void pushBack(int val) {
        if (tail == nullptr) {
            tail = new Node(val);
            front = tail;
            middle = tail;
        } else {
            Node * tmp = new Node(val);
            tail->next = tmp;
            tmp->back = tail;
            tail = tmp;
            if (!(size % 2)) {
                middle = middle->next;
            }
        }
        size++;
    }
    
    int popFront() {
        if (front == nullptr) {
            return -1;    
        }
        int answer = front->val;
        if (size == 1) {
            front = nullptr;
            middle = nullptr;
            tail = nullptr;
        } else {
            front = front->next;
            if (!(size % 2)) {
                middle = middle->next;
            }
        }
        size--;
        return answer;
    }
    
    int popMiddle() {
        if (middle == nullptr) {
            return -1;
        }
        int answer = middle->val;
        if (size == 1) {
            front = nullptr;
            middle = nullptr;
            tail = nullptr;
        } else {
            if (size % 2) {
                Node *tmp = middle->next;
                middle = middle->back;
                tmp->back = middle;
                middle->next = tmp;
            } else {
                Node *tmp = middle->back;
                middle = middle->next;
                if (size > 2) tmp->next = middle;
                middle->back = tmp;
                if (size == 2) {
                    front = middle;
                }
            }
        }
        size--;
        return answer;
    }
    
    int popBack() {
        if (tail == nullptr) {
            return -1;    
        }
        int answer = tail->val;
        if (size == 1) {
            front = nullptr;
            middle = nullptr;
            tail = nullptr;
        } else {
            tail = tail->back;
            if (size % 2) {
                middle = middle->back;
            }
        }
        size--;
        return answer;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */