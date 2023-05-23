class Solution 
{
public:
    int bSearch(int val, vector<int>& nums)
    {
        int m = 0, l = 0, r = nums.size();
        while (l < r)
        {
            m = (l + r) / 2;
            if (val > nums[m])
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        return l;
    }
    int maximumCount(vector<int>& nums) 
    {
        int l = 0, r = nums.size() - 1;
        int val = 0;
        int zero = bSearch(0, nums), one = bSearch(1, nums);
        int r1 = nums.size() - one;
        return (r1 > zero ? r1 : zero);
    }
};