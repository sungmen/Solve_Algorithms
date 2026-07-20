class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        return nums[std::min_element(nums.begin(), nums.end())-nums.begin()];
    }
};
