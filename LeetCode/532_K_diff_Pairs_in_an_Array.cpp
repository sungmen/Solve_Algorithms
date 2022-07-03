class Solution 
{
public:
    int findPairs(vector<int>& nums, int k) 
    {
        map<int, int> m;
        
        for(auto n : nums)
        {
            m[n] ++;
        }
        
        int ans = 0;
        
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (k)
            {
                ans += (m.find(it->first + k) != m.end());
            }
            else
            {
                ans += (it->second > 1);
            }
        }
        
        return ans;
    }
};