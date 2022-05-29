class Solution 
{
public:
    int minFlips(string target) 
    {
        char chk = '0';
        int ans = 0;
        
        for (auto tar : target)
        {
            if (chk != tar)
            {
                ans++;
                
                chk = ('0' == chk ? '1' : '0');
            }
        }
        
        return ans;
    }
};