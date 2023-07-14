class Solution 
{
public:
    int destroyTargets(vector<int>& nums, int space) 
    {
        int maxValue = -1;
        unordered_map<int, int> um;
        map<int, int> m;
        for (auto n : nums)
        {
            int t = ++um[n % space];
            m[n] = n%space;
            maxValue = max(maxValue, t);
        }
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (um[it->second] == maxValue) return it->first;
        }

        return 0;
    }
};