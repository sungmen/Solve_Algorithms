class Solution 
{
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) 
    {
        int n = nums.size();
        vector<int> res(n, 0);
        int b = (1 << maximumBit) - 1;
        int t = 0;
        for (int i = 0; i < n; i++)
        {
            t ^= nums[i];
            res[n - i - 1] = b ^ t;
        }
        return res;
    }
};