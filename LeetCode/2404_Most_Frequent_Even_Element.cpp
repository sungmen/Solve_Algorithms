class Solution 
{
public:
    int mostFrequentEven(vector<int>& nums) 
    {
        map<int, int> um;
        for (auto n : nums)
        {
            if (!(n % 2)) um[n]++;
        }
        int res = 0;
        int ans = -1;
        for (auto it = um.begin(); it != um.end(); it++)
        {
            if (res < it->second)
            {
                res = it->second;
                ans = it->first;
            }
        }
        return ans;
    }
};