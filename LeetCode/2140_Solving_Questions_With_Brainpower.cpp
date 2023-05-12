class Solution 
{
public:
    long long mostPoints(vector<vector<int>>& questions) 
    {
        int n = questions.size();
        vector<long long> dp(n, 0);
        dp[n-1] = questions[n - 1][0];
        for (int i = n - 2; i >= 0; i--)
        {
            int p = questions[i][0];
            int b = questions[i][1];
            long long cur = b + i + 1;
            long long curTask = (cur >= n ? 0 : dp[cur]);
            dp[i] = max(dp[i + 1], curTask + p);
        }

        return dp[0];
    }
};