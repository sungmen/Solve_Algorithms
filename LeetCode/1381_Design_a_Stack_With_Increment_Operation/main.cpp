class CustomStack {
private:
    int maxSize;
    vector<int> v;
    int idx = 0;
public:
    CustomStack(int maxSize) : maxSize(maxSize) {
        v.resize(1001, -1);
    }
    
    void push(int x) {
        if (idx < maxSize) v[++idx] = x;
    }
    
    int pop() {
        return (idx > 0 ? v[idx--] : v[idx]);
    }
    
    void increment(int k, int val) {
        for (int i = 1; i <= k; i++) {
            v[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */