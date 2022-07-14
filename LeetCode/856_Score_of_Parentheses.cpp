class Solution 
{
public:
    int scoreOfParentheses(string s) 
    {
        int d = 0, ans = 0;
        char b = '-';
        for (auto c : s)
        {
            if ('(' == c)
            {
                d++;  
            }
            else
            {
                d--;
            }
            if ('(' == b && ')' == c)
            {
                ans += pow(2.0, d);
            }
            b = c;
        }
        return ans;
    }
};