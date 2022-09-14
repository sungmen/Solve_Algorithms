class Solution 
{
public:
    int countAsterisks(string s) 
    {
        int p = 0, b = 0;
        for (auto c : s)
        {
            if ('*' == c && 0 == (b % 2))
            {
                p++;
            }
            if ('|' == c)
            {
                b++;
            }
        }
        
        return p;
    }
};