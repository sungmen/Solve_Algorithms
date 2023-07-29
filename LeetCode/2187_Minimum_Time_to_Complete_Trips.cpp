class Solution 
{
public:
    long long minimumTime(vector<int>& time, int totalTrips) 
    {
        long long l = 0, r = (long long)time[0] * (long long)totalTrips;
        while (l < r)
        {
            long long m = l + (r - l) / 2;
            long long next = 0;
            for (auto t : time)
            {
                next += m / t;
            }
            if  (next < totalTrips)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};