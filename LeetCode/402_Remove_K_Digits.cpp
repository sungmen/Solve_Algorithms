class Solution 
{
public:
    string removeKdigits(string num, int k) 
    {
        if (num.size() <= k) return "0";
        string stk = "";
        int i = 0;
        for (; i < num.size() && k > 0; i++)
        {
            if (stk.empty())
            {
                if ('0' != num[i])
                    stk.push_back(num[i]);
                continue;
            }
            while (!stk.empty() && stk.back() > num[i] && k > 0)
            {
                stk.pop_back();
                k--;
            }
            while (!stk.empty() && '0' == stk.back()) stk.pop_back();
            if (stk.empty() && '0' == num[i]) continue;
            stk.push_back(num[i]);
        }
        for (;i < num.size(); i++)
        {
            if (stk == "" && '0' == num[i]) continue;
            stk += num[i];
        }
        if (stk.size() <= k) return "0";
        string ans = stk.substr(0, stk.size() - k);
        return ans == "" ? "0" : ans;
    }
};