class Solution 
{
public:
    int minimumMoves(string s) 
    {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)    
        {
            if ('X' == s[i])
            {
                cnt++;
                for (int j = i; j < i + 3 && j < s.size(); j++)
                {
                    s[j] = 'O';
                }
            }
        }
        return cnt;
    }
};