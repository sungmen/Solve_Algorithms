class Solution 
{
public:
    int minMoves(vector<int>& nums) 
    {
        int res = 0;
        int minn = INT_MAX;
        for (auto num : nums)
        {
            minn = min(minn, num);
            res += num;
        }

        return res - (minn * nums.size());
    }
};