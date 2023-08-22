class Solution 
{
public:
    int findNonMinOrMax(vector<int>& nums) 
    {
        if (nums.size() <= 2) return -1;
        int mn = 101, ma = 0;
        for (int i = 0; i < 3; i++)
        {
            mn = min(mn, nums[i]);
            ma = max(ma, nums[i]);
        }
        for (int i = 0; i < 3; i++)
        {
            if (mn == nums[i] || ma == nums[i]) continue;
            return nums[i];
        }
        return -1;
    }
};