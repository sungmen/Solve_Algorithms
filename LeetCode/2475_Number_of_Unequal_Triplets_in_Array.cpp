class Solution 
{
public:
    int unequalTriplets(vector<int>& nums) 
    {
        map<int, int> m;
        for (auto num : nums)
        {
            m[num]++;
        }
        int result = 0, l = 0, r = nums.size();
        for (auto it = m.begin(); it != m.end(); it++)
        {
            r -= it->second;
            result += it->second * r * l;
            l += it->second;
        }
        return result;
    }
};