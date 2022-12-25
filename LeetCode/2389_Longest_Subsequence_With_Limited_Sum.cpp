class Solution 
{
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) 
    {
        vector<int> res;
        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] += nums[i - 1];
        }
        for (auto querie : queries)
        {
            auto it = upper_bound(nums.begin(), nums.end(), querie);
            int idx = it - nums.begin();
            res.push_back(idx);
        }
        return res;
    }
};