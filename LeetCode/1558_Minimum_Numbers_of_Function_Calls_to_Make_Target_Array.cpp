class Solution 
{
public:
    int minOperations(vector<int>& nums) 
    {
        int maxMul = 0;
        int bit = 0;
        for (auto num : nums)
        {
            int r = 0;
            while (num)
            {
                if (num%2)bit++;
                ++r;
                num /= 2;
            }
            maxMul = max(maxMul, r);
        }
        bit += maxMul;
        return bit?bit - 1 : 0;
    }
};