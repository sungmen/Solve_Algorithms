class Solution 
{
public:
    int repeatedNTimes(vector<int>& nums) 
    {
        int n = nums.size();
        map<int, int> m;
        for (auto num : nums)
        {
            m[num]++;
        }
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second == n / 2)
            {
                return it->first;
            }
        }
        return 0;
    }
};