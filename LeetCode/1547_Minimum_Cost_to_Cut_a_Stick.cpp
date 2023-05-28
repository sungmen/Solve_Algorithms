class Solution {
public:
    int minCost(int length, vector<int>& cuts) {
        int n = cuts.size();
        cuts.push_back(0);
        cuts.push_back(length);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        int i = n;
        while (i >= 1)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i > j) continue;
                dp[i][j] = 1e9;
                for (int k = i; k <= j; k++)
                {
                    int res = cuts[j + 1] - cuts[i - 1];
                    res += dp[i][k - 1];
                    res += dp[k + 1][j];
                    dp[i][j]= min(dp[i][j], res);
                }
            }
            i--;
        }
        return dp[1][n];
    }
};