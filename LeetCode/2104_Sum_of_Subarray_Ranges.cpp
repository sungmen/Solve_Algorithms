class Solution 
{
public:
    long long subArrayRanges(vector<int>& nums) 
    {
        long long ans = 0;
        int m = nums.size();
        for (int i = 0; i < m; i++)
        {
            int fir = nums[i], sec = nums[i];
            for (int j = i; j < m; j++)
            {
                fir = max(fir, nums[j]);
                sec = min(sec, nums[j]);
                ans += fir - sec;
            }
        }
        return ans;
    }
};