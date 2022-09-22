class Solution 
{
public:
    int countKDifference(vector<int>& nums, int k) 
    {
        map<int, int> m;
        for (auto num : nums)
        {
            m[num]++;
        }
        
        int cnt = 0;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (m.find(k + it->first) != m.end())
            {
                cnt += (m[k + it->first] * it->second);
            }
        }
        
        return cnt;
    }
};