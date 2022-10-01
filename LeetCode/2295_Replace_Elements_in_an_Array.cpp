class Solution 
{
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) 
    {
        unordered_map<int, int> um;
        vector<int> v(nums.size());
        for (int i = 1; i <= nums.size(); i++)
        {
            um[nums[i-1]] = i;
        }
        for (auto operation : operations)
        {
            int t = um[operation[0]];
            um.erase(operation[0]);
            um[operation[1]] = t;
        }
        for (auto it = um.begin(); it != um.end(); it++)
        {
            v[it->second - 1] = it->first;
        }
        return v;
    }
};