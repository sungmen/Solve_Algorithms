class Solution 
{
public:
    int minFlipsMonoIncr(string s) 
    {
        int res = 1e9;
        int l = 0, r = 0;
        for (auto c : s)
            if ('0' == c)
                r++;
        for (auto c : s)
        {
            if ('0' == c)
                r--;
            res = min(res, r + l);
            if ('1' == c)
                l++;
        }
        return res;
    }
};