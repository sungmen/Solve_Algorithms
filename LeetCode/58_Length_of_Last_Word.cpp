class Solution 
{
public:
    int lengthOfLastWord(string s) 
    {
        int result = 0;
        int r = s.size() - 1;
        while (r >= 0 && s[r] == ' ')
        {
            r--;
        }
        
        while (r >= 0 && s[r] != ' ')
        {
            r--;
            result++;
        }
        
        return result;
    }
};