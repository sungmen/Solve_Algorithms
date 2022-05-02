class Solution 
{
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        int i = 0, j = 0, m = nums.size();
        while (j < m) 
        {
            if (nums[j] % 2 == 0)
            {
                swap(nums[i++], nums[j]);
            }
            j++;
        }
        return nums;
    }
};