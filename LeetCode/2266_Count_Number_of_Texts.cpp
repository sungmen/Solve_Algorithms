class Solution 
{
public:
    const int MOD = 1e9 + 7;

    int countTexts(string pressedKeys) 
    {
        vector<long long> dp(5, 0);
        dp[4] = 1;
        for (int i = 0; i < pressedKeys.size(); i++)
        {
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = dp[3];
            dp[3] = dp[4];
            if (i == 0) continue;
            if (pressedKeys[i] == pressedKeys[i-1]) dp[4] += dp[2];
            else continue;
            if (dp[4] >= MOD) dp[4] -= MOD;
            if (i == 1) continue;
            if (pressedKeys[i] == pressedKeys[i-2]) dp[4] += dp[1];
            else continue;
            if (dp[4] >= MOD) dp[4] -= MOD;
            if (i == 2) continue;
            if (pressedKeys[i] != '7' && pressedKeys[i] != '9') continue;
            if (pressedKeys[i] == pressedKeys[i-3]) dp[4] += dp[0];
            else continue;
            if (dp[4] >= MOD) dp[4] -= MOD;
        }
        return (int)dp[4];
    }
};