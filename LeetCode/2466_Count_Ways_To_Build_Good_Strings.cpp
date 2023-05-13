class Solution 
{
public:
    const int MOD = 1e9 + 7;
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        vector<int> dp(high + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= high; i++)
        {
            long long t = ((i-zero>=0?dp[i-zero]:0) + (i-one>=0?dp[i-one]:0));
            if (t >= MOD) t -= MOD;
            dp[i] = t;
        }
        long long ans = 0;
        for (int i = low; i <= high; i++)
        {
            ans += dp[i];
            if (ans >= MOD) ans -= MOD;
        }
        return (int)ans;
    }
};