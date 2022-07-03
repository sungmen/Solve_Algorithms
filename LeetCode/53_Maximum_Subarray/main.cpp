class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp[nums.size()];
        memset(dp, 0, sizeof(dp));
        dp[0] = nums[0];
        int max_v = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = nums[i] + dp[i-1];
            if (max_v < dp[i]) max_v = dp[i];
        }
        for (int i = 1; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                dp[j] -= dp[i-1];
                if (max_v < dp[j]) max_v = dp[j];
            }
        }        
        return max_v;
    }
};