class Solution 
{
public:
    int secondsToRemoveOccurrences(string s) 
    {
        int n = s.size();
        vector<pair<int, int>> dp (n);
        dp[0].first = (s[0]=='0'?1:0);
        for (int i = 1; i < n; i++)
        {
            dp[i].first = dp[i-1].first;
            dp[i].second = dp[i-1].second;
            if (s[i] == '0')
                dp[i].first++;
            else if (dp[i].first > 0)
                dp[i].second = max(dp[i].second + 1, dp[i].first);
            
        }
        return dp[n-1].second;
    }
};