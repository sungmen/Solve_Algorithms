class Solution {
public:
    int minSwaps(string s) {
        string stk = "";
        for (auto c : s) {
            if (c == '[') stk += c;
            else {
                if (!stk.empty() && stk.back() == '[') {
                    stk.pop_back();
                } else {
                    stk += c;
                }
            }
        }
        int ans = 0;
        if (!stk.size()) return 0;
        else {
            for (int i = 0; i < stk.size(); i += 2) {
                if (stk.substr(i, 2) == "[[" || stk.substr(i, 2) == "]]") ans += 1;
                else if (stk.substr(i, 2) == "][") ans += 2;
            }
        }
        return ans / 2;
    }
};