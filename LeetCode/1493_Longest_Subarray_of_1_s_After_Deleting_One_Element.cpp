class Solution 
{
public:
    int longestSubarray(vector<int>& nums) 
    {
        vector<pair<int, int>> dp(nums.size(), {0, 0});
        int res = 0;
        int b = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (0 == nums[i])
            {
                dp[i].first = 0;
                dp[i].second = 0;
                b = 0;
                continue;
            }
            if (i > 0)
            {
                if (i > 1 && 0 == nums[i-1])
                {
                    dp[i].first = dp[i-2].second + 1;
                }
                else
                    dp[i].first = dp[i-1].first + 1;
                dp[i].second = dp[i-1].second + 1;
            }
            else
            {
                dp[i].first = 1;
                dp[i].second = 1;
            }
            res = max(res, max(dp[i].first, dp[i].second));
        }
        if (b) return nums.size() - 1;
        return res;
    }
};