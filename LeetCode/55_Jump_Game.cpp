class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        int cur = 0;
        int t = 0;
        while (cur < nums.size() && t <= cur)
        {
            cur = max(cur, t + nums[t]);
            t++;
        }
        return cur >= nums.size() - 1;
    }
};