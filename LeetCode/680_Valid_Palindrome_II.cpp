class Solution 
{
public:
    bool validPalindrome(string s, int l = -1, int r = -1, int c = 1) 
    {
        if (l == -1 && r == -1 && c == 1)
        {
            l = 0;
            r = s.size() - 1;
        }
        bool chk = 1;
        while (l < r)
        {
            if (s[l] == s[r])
            {
                l++;
                r--;
            }
            else if (c == 0)
                return 0;
            else
            {
                return validPalindrome(s, l+1, r, 0) || validPalindrome(s, l, r-1, 0);
            }
        }
        return 1;
    }
};