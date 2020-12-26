/**
* Runtime: 20 ms, faster than 58.44% of C++ online submissions for Remove All Adjacent Duplicates in String II.
* Memory Usage: 8.3 MB, less than 75.64% of C++ online submissions for Remove All Adjacent Duplicates in String II.
*/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stk;
        stk.push({s[0], 1});
        for (int i = 1; i < s.size(); i++) {
            if(!stk.empty()) {
                if (stk.top().first == s[i]) {
                    if (stk.top().second == k - 1) {
                        stk.pop();
                    } else {
                        stk.top().second += 1;
                    }
                } else {
                    stk.push({s[i], 1});
                }
            } else {
                stk.push({s[i], 1});
            }
        }
        string result = "";
        while(!stk.empty()) {
            for (int i = 0; i < stk.top().second; i++) result += stk.top().first;
            stk.pop();                
        }
        for (int i = 0; i < result.size() / 2; i++) {
            char tmp = result[i];
            result[i] = result[result.size() - 1 - i];
            result[result.size() - 1 - i] = tmp;
        }
        return result;
    }
};
