class Solution 
{
public:
    int longestPalindromeSubseq(string s) 
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
            for (int j = i - 1; j >= 0; j--)
            {
                dp[i][j] = (s[i] == s[j] ? dp[i - 1][j + 1] + 2 : max(dp[i - 1][j], dp[i][j + 1]));
            }
        }
        
        return dp[n - 1][0];
    }
};