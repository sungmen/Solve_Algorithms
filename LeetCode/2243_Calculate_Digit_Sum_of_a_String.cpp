class Solution 
{
public:
    string digitSum(string s, int k) 
    {
        while(s.size() > k)
        {
            string next = "";
            int n = 0;
            for (int i = 1; i <= s.size(); i++)
            {
                n += (s[i - 1] - '0');
                if (0 == (i % k))
                {
                    next += to_string(n);
                    n = 0;
                }
            }
            if (0 < (s.size() % k))
            {
                next += to_string(n);
            }
            s = next;
        }
        return s;
    }
};