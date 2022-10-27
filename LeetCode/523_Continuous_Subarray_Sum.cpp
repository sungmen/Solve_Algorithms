class Solution 
{
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int, int> um;
        um[0] = -1;
        long long cur = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            cur = (cur + nums[i]) % k;
            if (um.find(cur) != um.end())
            {
                if (um[cur] < i - 1) 
                {
                    return true;
                }
            }
            else
            {
                um[cur] = i;
            }
        }
        return false;
    }
};