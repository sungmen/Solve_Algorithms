class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int l = 0, r = 0;
        stack<int> stk;
        while(l < pushed.size()) {
            if (stk.empty()) {
                stk.push(pushed[l++]);
            } else if (stk.top() != popped[r]) {
                stk.push(pushed[l++]);
            } else {
                stk.pop();
                ++r;
            }
        }
        while (r < popped.size()) {
            if (!stk.empty() && stk.top() == popped[r]) {
                stk.pop();
                ++r;
            } else {
                return false;
            }
        }        
        return true;
    }
};