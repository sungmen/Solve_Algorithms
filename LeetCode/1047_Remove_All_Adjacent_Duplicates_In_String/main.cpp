/**
* Runtime: 32 ms, faster than 63.41% of C++ online submissions for Remove All Adjacent Duplicates In String.
* Memory Usage: 11.1 MB, less than 35.50% of C++ online submissions for Remove All Adjacent Duplicates In String.
*/

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> stk;
        stk.push(S[0]);
        for (int i = 1; i < S.size(); i++) {
            if(!stk.empty()) {
                if(stk.top() == S[i]) stk.pop();
                else stk.push(S[i]);
            } else {
                stk.push(S[i]);
            }
        }
        string result;
        while(!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        for (int i = 0; i < result.size()/2; i++) {
            char tmp = result[i];
            result[i] = result[result.size() - 1 - i];
            result[result.size() - 1 - i] = tmp;
        }
        return result;
    }
};