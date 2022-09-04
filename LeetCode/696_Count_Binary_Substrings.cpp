class Solution 
{
public:
    int countBinarySubstrings(string s) 
    {
        vector<int> v;
        int t = (s[0] - '0' == 0 ? -1 : 1);
        int b = (s[0] - '0');
        for (int i = 1; i < s.size(); i++)
        {
            if (b != s[i] - '0')
            {
                v.push_back(abs(t));
                b = (s[i] - '0');
                t = (s[i] - '0' == 0 ? -1 : 1);
            }
            else
            {
                t += (s[i] - '0' == 0 ? -1 : 1);
            }
        }
        v.push_back(abs(t));
        if (v.size() <= 1)
        {
            return 0;
        }
        int res = 0;
        for (int i = 0; i < v.size() - 1; i++)
        {
            res += min(v[i], v[i + 1]);
        }
        
        return res;
    }
};
