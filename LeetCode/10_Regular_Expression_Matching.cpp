class Solution 
{
public:
    bool isMatch(string s, string p) 
    {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i < p.size(); i++)
        {
            if (p[i] != '*' || 0 == dp[0][i-1]) continue;
            dp[0][i + 1] = 1;
        }
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < p.size(); j++)
            {
                if (p[j] == s[i] || p[j] == '.')
                    dp[i + 1][j + 1] = dp[i][j];
                if (p[j] != '*') continue;
                dp[i+1][j+1] = (p[j-1] != s[i] && p[j-1] != '.') ? dp[i+1][j-1] : (dp[i+1][j] || dp[i][j+1] || dp[i+1][j-1]);
            }
        }
        return dp[s.size()][p.size()]; 
    }
};