class Solution 
{
public:
    string makeGood(string s) 
    {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++)
        {
            if (!stk.empty())
            {
                bool c1 = 0, c2 = 0;
                int t1 = 0, t2 = 0;
                char stop = stk.top();
                if ('a' <= s[i] && 'z' >= s[i])
                {
                    t1 = s[i] - 'a';
                }
                else if ('A' <= s[i] && 'Z' >= s[i])
                {
                    t1 = s[i] - 'A';
                    c1 = 1;
                }
                if ('a' <= stop && 'z' >= stop)
                {
                    t2 = stop - 'a';
                }
                else if ('A' <= stop && 'Z' >= stop)
                {
                    t2 = stop - 'A';
                    c2 = 1;
                }
                if (c1 != c2 && t1 == t2)
                {
                    stk.pop();
                    continue;
                }
            }
            stk.push(s[i]);
        }
        string res = "";
        while (!stk.empty())
        {
            res = stk.top() + res;
            stk.pop();
        }
        return res;
    }
};