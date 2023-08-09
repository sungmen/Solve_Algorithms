class Solution 
{
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) 
    {
        set<int> um;
        int diff = 0;
        for (int n : aliceSizes)
        {
            diff -= n;
        }
        for (int n : bobSizes)
        {
            um.insert(n);
            diff += n;
        }
        diff /= 2;
        for (int n : aliceSizes)
        {
            int t = diff + n;
            if (um.find(t) == um.end()) continue;
            return {n, t};
        }
        return {0, 0};
    }
};