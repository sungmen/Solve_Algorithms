class Solution 
{
public:
    int arithmeticTriplets(vector<int>& nums, int diff) 
    {
        map<int, int> m;
        for (auto num : nums)
        {
            m[num] = 1;
        }
        
        int res = 0;
        
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (m.find(it->first - diff) != m.end() && m.find(it->first + diff) != m.end())
            {
                res ++;
            }
        }
        
        return res;
    }
};