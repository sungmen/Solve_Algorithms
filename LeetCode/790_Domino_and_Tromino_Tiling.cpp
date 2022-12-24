class Solution 
{    
public:
    int numTilings(int n) 
    {
        int MOD = 1000000007;
        vector<int> dp(1001, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= 1000; i++)
        {
            dp[i] = ((2 * dp[i-1]) % MOD + dp[i - 3]) % MOD;
        }
        return dp[n];
    }
};