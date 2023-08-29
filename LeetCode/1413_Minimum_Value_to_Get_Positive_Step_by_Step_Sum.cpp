class Solution 
{
public:
    int minStartValue(vector<int>& nums) 
    {
        int n = 0, res = 0;
        for (auto i : nums)
        {
            res += i;
            n = min(n, res);
        }       
        return 1 - n;
    }
};