class Solution 
{
public:
    int minKBitFlips(vector<int>& nums, int k) 
    {
        int n = nums.size();
        bool flip = 0;
        int ans = 0;
        vector<bool> dp(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (k <= i) flip ^= dp[i-k];
            if (flip != nums[i]) continue;
            if (n < i + k) return -1;
            dp[i] = 1;
            flip ^= 1;
            ans++;
        }
        return ans;
    }
};