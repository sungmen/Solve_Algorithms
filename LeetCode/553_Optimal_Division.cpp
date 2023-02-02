class Solution 
{
public:
    string optimalDivision(vector<int>& nums) 
    {
        if (1 == nums.size()) return to_string(nums[0]);
        if (2 == nums.size()) return to_string(nums[0]) + "/" + to_string(nums[1]);
        string ans = to_string(nums[0]) + "/(";
        for (int i = 1; i < nums.size(); i++)
        {
            ans += to_string(nums[i]);
            if (i == nums.size() - 1) continue;
            ans += "/";
        }
        return ans + ")";
    }
};