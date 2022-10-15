class Solution 
{
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        vector<int> result(nums.size());
        int o = 0, r = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                result[o] = nums[i];
                o += 2;
            }
            else
            {
                result[r] = nums[i];
                r += 2;
            }
        }
        return result;
    }
};