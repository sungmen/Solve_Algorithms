class Solution 
{
public:
    int dfs(int l, int r, vector<vector<int>>& dp, vector<int>& nums)
    {
        if (-1 != dp[l][r]) return dp[l][r];
        else if (l == r) return nums[l];
        int re = max(nums[l] - dfs(l+1,r,dp,nums), nums[r] - dfs(l,r-1,dp,nums));
        dp[l][r] = re;
        return re;
    }

    bool predictTheWinner(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return dfs(0, n - 1, dp, nums) >= 0;
    }
};