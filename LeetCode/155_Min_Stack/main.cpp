/*
    Runtime: 32 ms, faster than 73.72% of C++ online submissions for Min Stack.
    Memory Usage: 16.4 MB, less than 86.91% of C++ online submissions for Min Stack.
*/

class MinStack {
private:
    vector<int> stk;
    vector<pair<int, int>> min_stk;
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        stk.push_back(x);
        if(!min_stk.empty()) {
            if(min_stk.back().first == x) min_stk.back().second+=1;
            else if(min_stk.back().first > x) min_stk.push_back({x, 1});
        } else {
            min_stk.push_back({x, 1});
        }
    }
    
    void pop() {
        if(!min_stk.empty() && !stk.empty()) {
            if(min_stk.back().first == stk.back()) {
                if (min_stk.back().second == 1) min_stk.pop_back();
                else if (min_stk.back().second > 1) min_stk.back().second -= 1;
            }
        }
        if(!stk.empty()) {
            stk.pop_back();
        }
    }
    
    int top() {
        if(!stk.empty()) {
            return stk.back();
        }
        return 0;
    }
    
    int getMin() {
        if(!min_stk.empty()) {
            return min_stk.back().first;
        }
        return 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */