class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp = matrix;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = m - 2; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                if (!j) {
                    dp[i][j] = matrix[i][j] + min(dp[i+1][0], dp[i+1][1]);
                } else if (j == n - 1) {
                    dp[i][j] = matrix[i][j] + min(dp[i+1][j-1], dp[i+1][j]);
                } else {
                    dp[i][j] = matrix[i][j] + min(dp[i+1][j-1], min(dp[i+1][j], dp[i+1][j+1]));
                }
                cout << dp[i][j] << ' ';
            }
        }
        return dp[0][distance(dp[0].begin(), min_element(dp[0].begin(), dp[0].end()))];
    }
};