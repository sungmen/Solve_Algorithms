class Solution 
{
public:
    int largestAltitude(vector<int>& gain) 
    {
        int n = 0;
        int nMax = 0;
        for (auto i : gain)
        {
            n += i;
            nMax = max(n, nMax);
        }
        return nMax;
    }
};