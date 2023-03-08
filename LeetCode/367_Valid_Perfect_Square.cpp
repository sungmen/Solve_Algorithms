class Solution 
{
public:
    bool isPerfectSquare(int num) 
    {
        int l = 0, r = num;
        while (l <= r)    
        {
            long long m = (l + r) / 2;
            if (m * m == num)
                return 1;
            else if (m * m < num)
            {
                l = m + 1;
            }
            else
                r = m - 1;
        }
        return 0;
    }
};