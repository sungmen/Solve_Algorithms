class Solution 
{
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int n = weights.size();
        int l = 0;
        int r = 0;
        for (int i = 0; i < n; i++)
        {
            r += weights[i];
            l = max(l, weights[i]);
        }
        while (l <= r)
        {
            int m = (l + r) / 2;
            int day = 1;
            int sum = 0;
            for (auto i : weights)
            {
                if (m < sum + i)
                {
                    day++;
                    sum = 0;
                }
                sum += i;
            }
            if (days < day)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return l;
    }
};