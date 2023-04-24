class Solution 
{
public:
    const int MOD = 1e9 + 7;
    int numberOfArrays(string s, int k) 
    {
        vector<long long> dp(s.size() + 1, 0);
        dp[s.size()] = 1;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if ('0' == s[i]) continue;

            long long n = 0;
            for (int j = i + 1; j <= s.size(); ++j)
            {
                n = n * 10 + (s[j - 1] - '0');
                if (n > k) break;
                dp[i] += dp[j];
                dp[i] %= MOD;
            }
        }
        return dp[0] % MOD;
    }
};