class Solution 
{
public:
    
    unordered_map<int, int> um;
    bool prim[31];
    void pri()
    {
        for (int i = 0; i < 31; i++) prim[i] = 1;
        prim[0] = prim[1] = 0;
        for (int i = 2; i <= 30; i++)
        {
            if (prim[i])
            {
                um[i] = 1;
                for (int j = i + i; j <= 30; j += i)
                {
                    prim[j] = 0;
                }
            }
        }
    }
    
    int countPrimeSetBits(int left, int right) 
    {
        pri();
        int ans = 0;
        for (int i = left; i <= right; i++)
        {
            if (um[__builtin_popcount(i)])
            {
                ans++;
            }
        }
        return ans;
    }
};