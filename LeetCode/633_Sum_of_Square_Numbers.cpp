class Solution 
{
public:
    bool judgeSquareSum(int c) 
    {
        long long l = 0, r = sqrt(c);
        while (l <= r)
        {
            long long m = (l * l) + (r * r);
            if (m == c)
            {
                return true;
            }
            else if (m < c)
                l++;
            else 
                r--;
        }
        return false;
    }
};