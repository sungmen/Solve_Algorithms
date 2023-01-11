class Solution 
{
public:
    bool repeatedSubstringPattern(string s) 
    {
        if (s.size() == 1) return false;
        string r = "";
        for (int i = 0; i < s.size() / 2; i++)
        {
            r += s[i];
            if (r + s == s + r)
            {
                return true;
            }
        }
        return false;
    }
};
