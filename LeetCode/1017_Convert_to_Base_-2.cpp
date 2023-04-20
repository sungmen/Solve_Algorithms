class Solution 
{
public:
    string baseNeg2(int n) 
    {
        if (0 == n) return "0";
        // 1 -2 4 -8 16 -32 64
        string res = "";
        while (0 != n)
        {
            int r = n % (-2);
            n /= (-2);
            if (r < 0)
            {
                r += 2;
                ++n;
            }
            res = to_string(r) + res;
        }

        return res;
    }
};