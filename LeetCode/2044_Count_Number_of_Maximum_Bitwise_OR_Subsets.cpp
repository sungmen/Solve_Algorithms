class Solution 
{
public:
    unordered_map<int, int> um;

    void dfs(vector<int>& nums, int n, int sum)
    {
        um[sum]++;
        for (int i = n + 1; i < nums.size(); i++)
        {
            dfs(nums, i, sum | nums[i]);
        }
    }

    int countMaxOrSubsets(vector<int>& nums) 
    {
        for (int i = 0; i < nums.size(); i++)
        {
            dfs(nums, i, nums[i]);
        }
        
        int res = 0;
        for (auto it = um.begin(); it != um.end(); it++)
        {
            res = max(res, it->second);
        }

        return res;
    }
};