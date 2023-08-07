class Solution 
{
public:
    int countNumbersWithUniqueDigits(int n) 
    {
        if (0 == n) return 1;
        int ans = 10, mul = 9;
        for (int i = 1; i < n; i++)
        {
            mul *= (10 - i);
            ans += mul;
        }

        return ans;
    }
};