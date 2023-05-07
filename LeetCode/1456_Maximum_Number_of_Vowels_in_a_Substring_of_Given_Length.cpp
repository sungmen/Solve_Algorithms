class Solution 
{
public:
    bool check(char c)
    {
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u')?1:0;
    }
    int maxVowels(string s, int k) 
    {
        int res = 0, cur = 0;
        for (int i = 0; i < k; i++)
            if (check(s[i]))
                cur++;
        res = cur;
        for (int i = k; i < s.size(); i++)
        {
            if (check(s[i-k])) cur--;
            if (check(s[i])) cur++;
            res = max(cur, res);
        }
        return res;
    }
};