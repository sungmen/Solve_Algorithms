class Solution 
{
public:
    bool checkIfCanBreak(string s1, string s2) 
    {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if (s1 == s2)
        {
            return true;
        }
        int res = 0;
        int nSize = s1.size();
        for (int i = 0; i < nSize; i++)
        {
            if (s1[i] < s2[i])
            {
                res |= (1<<0);
            }
            else if (s2[i] < s1[i])
            {
                res |= (1<<1);
            }
            if (((1<<2)-1) == res)
            {
                return false;
            }
        }
        return true;
    }
};