class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int MIN = 1e9;
        constexpr int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int yLen = heights.size(), xLen = heights[0].size();
        vector<vector<int>> dp(yLen, vector<int>(xLen, INT_MAX));
        int x= 0, y = 0;
        dp[0][0] = 0;
        bool oneChk = 1;
        for (int i = 0; i < (yLen * xLen) - 1 && oneChk; i++) {
            oneChk = 0;
            for (int m = 0; m < yLen; m++) {
                for (int n = 0; n < xLen; n++) {
                    for (int l = 0; l < 4; l++) {
                        int nexty = m + pos[l][0];
                        int nextx = n + pos[l][1];
                        
                        if (nexty < 0 || nexty >= yLen || nextx < 0 || nextx >= xLen || dp[m][n] >= dp[nexty][nextx]) continue;
                        int dif = abs(heights[nexty][nextx] - heights[m][n]);
                        
                        if (dp[nexty][nextx] > max(dp[m][n], dif)) {
                            dp[nexty][nextx] = max(dp[m][n], dif);
                            oneChk = 1;
                        }
                    }
                }
            }
        }
        return dp[yLen - 1][xLen - 1];
    }
};