/**
* Runtime: 116 ms, faster than 68.76% of C++ online submissions for Daily Temperatures.
* Memory Usage: 40.5 MB, less than 69.07% of C++ online submissions for Daily Temperatures
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans(T.size(), 0);
        stack<pair<int, int>> stk;
        int before = T[T.size() - 1];
        int cnt = 0;
        stk.push({T[T.size()-1], T.size() - 1});
        for (int i = T.size() - 2; i >= 0; i--) {
            while(!stk.empty() && T[i] >= stk.top().first) {
                stk.pop();
            }
            if (!stk.empty()) {
                ans[i] = stk.top().second - i;
            } else {
                ans[i] = 0;
            }
            stk.push({T[i], i});
        }
        return ans;
    }
};