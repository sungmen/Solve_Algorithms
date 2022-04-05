class Solution 
{
public:
    int triangularSum(vector<int>& nums) 
    {
        int c = nums.size();
        while (c)
        {
            for (int i = 0; i < c - 1; i++)
            {
                nums[i] = (nums[i] + nums[i+1]) % 10;
            }
            c--;
        }
        return nums[0];
    }
};