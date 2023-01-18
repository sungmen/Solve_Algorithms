class Solution 
{
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int cur = 0, next = 0, maxNum = INT_MIN, minNum = INT_MAX, total = 0;
        for (auto num : nums)    
        {
            total += num;
            if (num < cur + num)
                cur += num;
            else
                cur = num;
            if (num < next + num)
                next = num;
            else
                next += num;
            if (maxNum < cur)
                maxNum = cur;
            if (minNum > next)
                minNum = next;
        }
        if (maxNum <= 0)
            return maxNum;
        if (maxNum > total - minNum)
            return maxNum;
        return total - minNum;
    }
};