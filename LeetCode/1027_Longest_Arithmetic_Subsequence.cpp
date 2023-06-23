class Solution 
{
public:
    int longestArithSeqLength(vector<int>& nums) 
    {
        int ans = 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(1001, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int k = nums[j] - nums[i] + 500;
                dp[j][k] = max(2, dp[i][k] + 1);
                ans = max(ans, dp[j][k]);
            }
        }

        return ans;
    }
};