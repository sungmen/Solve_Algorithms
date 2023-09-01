class Solution 
{
public:
    int maxCoins(vector<int>& piles) 
    {
        sort(piles.begin(), piles.end());
        int n = piles.size() - 2;
        int ans = 0;
        for (int i = 0; i < piles.size() / 3; i++)
        {
            ans += piles[n];
            n -= 2;
        }
        return ans;
    }
};