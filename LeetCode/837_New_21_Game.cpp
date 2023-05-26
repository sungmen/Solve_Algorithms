class Solution 
{
public:
    double dp[10001];
    double new21Game(int n, int k, int maxPts) 
    {
        if (!k || n-k>=maxPts) return 1.0;
        dp[0] = 1;
        double res = 0.0;
        double s = 1.0;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = s / maxPts;
            if (i < k)
            {
                s += dp[i];
            }
            else
            {
                res += dp[i];
            } 
            if (i >= maxPts)
            {
                int c = i - maxPts;
                s -= dp[c];
            }
        }
        return res;    
    }
};