class Solution 
{
public:
    bool isPowerOfFour(int n) 
    {
        map<int, int> m;
        if (n <= 0)
        {
            return 0;
        }
        m[1] = 1;
        long long i = 4;
        while (i < INT_MAX)
        {
            m[i] = 1;
            i *= 4;
        }
        
        return m[n];
    }
};