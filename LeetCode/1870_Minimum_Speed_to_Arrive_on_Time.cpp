class Solution 
{
public:
    int minSpeedOnTime(vector<int>& dist, double hour) 
    {
        int n = dist.size();
        int ans = -1;

        int l = 1, r = (int)1e7;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            double tmp = 0;
            for (int i = 0; i < n - 1; i++)
            {
                tmp += ceil(dist[i]/(double)m);
            }
            tmp += dist[n-1] / (double)m;
            if (tmp <= hour)
            {
                r = m - 1;
                ans = m;
            }
            else
                l = m + 1;
        }

        return ans;
    }
};