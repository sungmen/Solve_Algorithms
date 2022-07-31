class Solution 
{
public:
    vector<int> numberOfPairs(vector<int>& nums) 
    {
        map<int, int> m;
        for (auto num : nums)
        {
            m[num] ++;
        }
        
        vector<int> v(2, 0);
        
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second % 2)
            {
                v[1] ++;
            }
            v[0] += (it->second / 2);
        }
        
        return v;
    }
};