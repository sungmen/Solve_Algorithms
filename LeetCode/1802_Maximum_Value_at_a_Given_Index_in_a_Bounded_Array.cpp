class Solution 
{
public:
    int maxValue(int n, int index, int maxSum) 
    {
        int l = 0, r = maxSum;
        long long m = 0;
        long long tmp = 0;
        int dif = maxSum - n;
        int t = n - index - 1;
        while (l < r)
        {
            m = (l + r + 1) / 2;
            tmp = m * m;
            long long p = 0;
            if (m > index) p += (m - index) * (m - index) - m + index;
            if ( m > t) p += ((m - t) * (m - t) - m + t);
            tmp -= p / 2;
            if (tmp > dif)
                r = m - 1;
            else 
                l = m;
        }

        return l + 1;
    }
};