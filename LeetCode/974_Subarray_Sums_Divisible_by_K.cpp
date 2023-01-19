class Solution 
{
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        unordered_map<int, int> um;
        int res = 0, sum = 0;
        um[0] = 1;
        for (auto num : nums)
        {
            sum = (sum + num) % k;
            if (sum < 0) sum += k;
            res += um[sum];
            um[sum]++;
        }
        return res;
    }
};