class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        for (int i = 0; i < nums.size() - 3; i++)
        {
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                int l = j + 1;
                int r = nums.size() - 1;
                while (l < r)
                {
                    long long sum = (long long)nums[i] +  (long long)nums[j] +  (long long)nums[l] +  (long long)nums[r];
                    if (target == sum)
                    {
                        s.insert({nums[i], nums[j], nums[l], nums[r]});
                        r--;
                    }
                    else if (target > sum)
                        l++;
                    else
                        r--;
                }
            }
        }
        vector<vector<int>> res;
        for (auto it = s.begin(); it != s.end(); it++)
            res.push_back(*it);
        return res;
    }
};