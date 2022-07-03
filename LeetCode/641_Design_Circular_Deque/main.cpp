class Node {
public:
    int val;
    Node* next;
    Node* back;
    Node(){}
    Node(int val) {
        this->val = val;
        next=nullptr;
        back=nullptr;
    } 
};

class MyCircularDeque {
int size = 0, maxsize = 0;
Node* head = nullptr;
Node* tail = nullptr;
public:
    MyCircularDeque(int k) {
        maxsize = k;
    }
    
    bool insertFront(int value) {
        if (size >= maxsize) return false;
        if (head == nullptr) {
            head = new Node(value);
            tail = head;
            size++;
        } else {
            Node* tmp = new Node(value);
            tmp->next = head;
            head->back = tmp;
            head = tmp;
            size++;
        }
        return true;
    }
    
    bool insertLast(int value) {
        if (size >= maxsize) return false;
        if (tail == nullptr) {
            tail = new Node(value);
            head = tail;
            size++;
        } else {
            Node* tmp = new Node(value);
            tmp->back = tail;
            tail->next = tmp;
            tail = tmp;
            size++;
        }
        return true;
    }
    
    bool deleteFront() {
        if (head == nullptr) {
            return false;
        } else if (size == 1) {
            head = nullptr;
            tail = nullptr;
        }  else {
            head = head->next;
        }
        size--;
        return true;
    }
    
    bool deleteLast() {
        if (tail == nullptr) {
            return false;
        } else if (size == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->back;
        }
        size--;
        return true;
    }
    
    int getFront() {
        if (head == nullptr) return -1;
        else return head->val;
    }
    
    int getRear() {
        if (tail == nullptr) return -1;
        else return tail->val;
    }
    
    bool isEmpty() {
        return size ? 0 : 1;
    }
    
    bool isFull() {
        return size == maxsize ? 1 : 0;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */