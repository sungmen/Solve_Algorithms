class Solution 
{
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) 
    {
        long long mod = 1e9 + 7;
        long long wVal = 0;
        long long hVal = 0;
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        horizontalCuts.push_back(h);
        h = 0;
        for (auto horizon : horizontalCuts)
        {
            wVal = max(wVal, (long long)horizon - h);
            h = horizon;
        }
        
        sort(verticalCuts.begin(), verticalCuts.end());
        verticalCuts.push_back(w);
        w = 0;
        for (auto vertical : verticalCuts)
        {
            hVal = max(hVal, (long long)vertical - w);
            w = vertical;
        }
        
        long long ans = (wVal * hVal) % mod;
        
        return ans;
    }
};