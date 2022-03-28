class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        int ans = nums[0], l = 0, r = nums.size() - 1, m;
        while (l < r)
        {
            m = (l + r) / 2;
            if (nums[m] > ans) ans = nums[m];
            if (nums[r] < nums[m])
            {
                l = m + 1;
            }
            else if (nums[r] > nums[m])
            {
                r = m;
            }
            else
            {
                r--;
            }
        }
        return (nums[l] > ans ? ans : nums[l]);
    }
};