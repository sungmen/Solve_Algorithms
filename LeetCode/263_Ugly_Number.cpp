class Solution 
{
public:
    bool isUgly(int n) 
    {
        if (n <= 0)
        {
            return false;
        }
        while (0 == n % 5 || 0 == n % 3 || 0 == n % 2)
        {
            if (0 == n % 5)
                n /= 5;
            if (0 == n % 3)
                n /= 3;
            if (0 == n % 2)
                n /= 2;
        }
        if (1 == n)
            return true;
        return false;
    }
};