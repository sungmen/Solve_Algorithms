class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        next = nullptr;
    }
};

class MyLinkedList {
public:
    Node *head = new Node(0);
    int listSize = 0;
    /** Initialize your data structure here. */
    MyLinkedList() {
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (listSize <= index) return -1;
        Node *headNode = head;        
        int idx = 0;
        while (idx < index) {
            idx++;
            headNode = headNode->next;
        }
        return headNode->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if(listSize == 0) {
            head->val = val;
            ++listSize;
            return;
        }
        Node* addHead = new Node(val);
        addHead->next = head;
        head = addHead;
        ++listSize;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(listSize == 0) {
            head->val = val;
            ++listSize;
            return;
        }
        Node* addTail = new Node(val);
        Node* tmp = head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = addTail;
        ++listSize;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (listSize < index) return;
        if(index == 0) {
            Node* tmp = new Node(val);
            tmp ->next = head;
            head = tmp;
            ++listSize;
            return;
        }
        int idx = 1;
        Node* addIndex = new Node(val);
        Node* tmp = head;
        while (idx < index) {
            tmp = tmp->next;
            idx++;
        }
        Node* tmpNext = tmp->next;
        tmp->next = addIndex;
        tmp->next->next = tmpNext;
        ++listSize;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (listSize < index) return;
        if (index == 0) {
            head = head->next;
            --listSize;
            return;
        }
        int idx = 1;
        Node* tmp = head;
        while (idx < index) {
            tmp = tmp->next;
            idx++;
        }
        if (index == listSize) {
            tmp->next = nullptr;
            return;
        }
        tmp->next = tmp->next->next;
        --listSize;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */