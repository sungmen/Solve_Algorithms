class Solution 
{
public:
    int minimizeArrayValue(vector<int>& nums) 
    {
        long long res = 0;
        long long num = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            num += nums[i];
            res = max(res, ((i + num)/(i + 1)));
        }
        return res;
    }
};