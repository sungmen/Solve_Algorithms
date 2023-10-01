class Solution 
{
public:
    bool isMonotonic(vector<int>& nums) 
    {
        if (nums.size() <= 2) return 1;
        bool c = 0;
        int i = 1;
        while (nums[i-1] <= nums[i])
        {
            if (i + 1 >= nums.size()) return 1;
            i++;
        }
        i = 1;
        while (nums[i-1]>= nums[i])
        {
            if (i + 1 >= nums.size()) return 1;
            i++;
        }

        return 0;
    }
};