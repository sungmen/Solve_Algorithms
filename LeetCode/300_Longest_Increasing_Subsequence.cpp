class Solution 
{
private:
    int dp[100001];

public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int res = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            dp[i] = 1;

            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        res = max(res, dp[i]);
                    }
                }
            }
        }
        
        return res;
    }
};