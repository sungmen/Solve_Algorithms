class FreqStack {
private:
    unordered_map<int, int> um;
    priority_queue<vector<int>> pq;
    int cnt = 0;
public:
    FreqStack() {}
    
    void push(int val) {
        pq.push({++um[val], ++cnt, val});
    }
    
    int pop() {
        int tmp = pq.top()[2];
        pq.pop();
        um[tmp]--;
        return tmp;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */