class Solution 
{
public:
    vector<int> minSubsequence(vector<int>& nums) 
    {
        int sumAll = 0;
        for (auto n : nums) sumAll += n;
        sort(nums.begin(), nums.end());
        vector<int> res;
        int cnt = 0;
        for (int idx = nums.size() - 1; idx >= 0; idx--)
        {
            cnt += nums[idx];
            res.push_back(nums[idx]);
            if (cnt > sumAll - cnt) break;
        }
        return res;
    }
};