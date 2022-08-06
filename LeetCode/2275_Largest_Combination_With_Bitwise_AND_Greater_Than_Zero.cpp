class Solution 
{
public:
    int largestCombination(vector<int>& candidates) 
    {
        vector<int> v(24, 0);
        int ans = 0;
        for (auto candidate : candidates)
        {
            bitset<24> bits(candidate);
            for (int i = 0; i < 24; i ++)
            {
                if (bits[i])
                {
                    v[i]++;
                    if (ans < v[i])
                    {
                        ans = v[i];
                    }
                }
            }
        }
        return ans;
    }
};