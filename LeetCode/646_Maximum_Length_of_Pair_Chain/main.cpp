class Solution {    
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<int> dp(pairs.size(), 1);
        int result = 1;
        for (int i = 0; i < pairs.size(); ++i) {
            for (int j = i + 1; j < pairs.size(); ++j) {
                if (pairs[i][1] < pairs[j][0]) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
                if (dp[j] > result) result = dp[j];
            }
        }
        return result;
    }
};