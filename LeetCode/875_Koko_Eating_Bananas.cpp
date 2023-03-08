class Solution 
{
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int l = 1, r = piles[0];
        for (auto pile : piles) r = max(r, pile);
        while (l < r)
        {
            int m = (l + r) / 2;
            int k = 0;
            for (auto pile : piles)
            {
                k += ceil((double)pile / m);
            }
            if (k > h)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};