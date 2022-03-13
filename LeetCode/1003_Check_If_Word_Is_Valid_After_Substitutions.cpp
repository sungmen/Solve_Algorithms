class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto c : s) {
            if (c == 'c') {
                if (stk.size() >= 2 && stk.top() == 'b') {
                    stk.pop();
                    if (!stk.empty() && stk.top() == 'a') {
                        stk.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            } else {
                stk.push(c);
            }
        }
        return (stk.empty()?1:0);
    }
};