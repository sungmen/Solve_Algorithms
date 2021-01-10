/**
* Runtime: 12 ms, faster than 98.38% of C++ online submissions for Minimum Path Sum.
* Memory Usage: 10.1 MB, less than 55.90% of C++ online submissions for Minimum Path Sum.
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dp[n][m];
        memset(dp, 101, sizeof(dp));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) dp[0][i] = grid[0][i] + dp[0][i-1];
        for (int i = 1; i < n; i++) dp[i][0] = grid[i][0] + dp[i-1][0];
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = min(grid[i][j] + dp[i][j-1], grid[i][j] + dp[i-1][j]);
            }
        }
        return dp[n-1][m-1];
    }
};
