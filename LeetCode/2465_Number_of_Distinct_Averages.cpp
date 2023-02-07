class Solution 
{
public:
    int distinctAverages(vector<int>& nums) 
    {
        map<double, int> m;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() / 2; i++)
        {
            m[((double)nums[i] + nums[nums.size()-1-i])/2.0] = 1;
        }
        return m.size();
    }
};