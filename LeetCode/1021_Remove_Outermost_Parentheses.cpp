class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> stk;
        int lr[2] = {0, 0};
        bool chk = false;
        for (int i = 0; i < s.size(); i++)
        {
            lr[s[i]-'(']++;
            if (false == chk)
            {
                chk = true;
                stk.push(i);
            }
            else if (lr[0] == lr[1])
            {
                chk = false;
                stk.push(i);
            }
        }
        while (!stk.empty())
        {
            s.erase(s.begin() + stk.top());
            stk.pop();
        }
        return s;
    }
};