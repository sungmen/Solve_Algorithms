class Solution {
public:
    int dp[51][51];
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++)
            {
                if (0 == i)
                {
                    dp[i][j] = grid[i][j];
                }
                else
                {
                    dp[i][j] = 1e9;
                }
            }
        }
        int ans = 1e9;
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    dp[i][k] = min(dp[i][k], grid[i][k] + moveCost[grid[i-1][j]][k] + dp[i-1][j]);
                    if ((m - 1) == i)
                    {
                        ans = min(dp[i][k], ans);
                    }
                }
            }
        }
        return ans;
    }
};