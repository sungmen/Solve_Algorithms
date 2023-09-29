class Solution 
{
public:
    string decodeAtIndex(string s, int k) 
    {
        stack<long long> stk;
        stk.push(0);
        string ans = "";
        for (auto c : s)
        {
            long long l = 0;
            if (c >= '2' && c <= '9')
            {
                l = stk.top() * (c-'0');
                stk.push(l);
            }
            else
            {
                l = stk.top() + 1;
                stk.push(l);
            }
        }
        int n = stk.size();
        while (! stk.empty())
        {
            --n;
            k %= stk.top();
            if (k == 0 && (s[n-1]>='a'&&s[n-1]<='z'))
            {
                ans += s[n-1];
                return ans;
            }
            stk.pop();
        }
        return ans;
    }
};