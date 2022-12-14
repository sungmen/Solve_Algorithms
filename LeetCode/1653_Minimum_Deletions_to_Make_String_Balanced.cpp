class Solution 
{
public:
    int minimumDeletions(string s) 
    {
        vector<pair<int, int>> dp(s.size() + 1, {0, 0});
        for (int i = 0; i < s.size(); i++)
        {
            if ('a' == s[i])
            {
                dp[i+1].first = min(dp[i].first + 1, dp[i].second);
                dp[i+1].second = dp[i].second;
            }
            else
            {
                dp[i + 1].first = dp[i].first;
                dp[i + 1].second = dp[i].second + 1;
            }
        }
        return dp[s.size()].first;
    }
};