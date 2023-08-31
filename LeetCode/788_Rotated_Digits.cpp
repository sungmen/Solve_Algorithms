class Solution 
{
public:
    int rotatedDigits(int n) 
    {
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            int cur = i;
            int d = 0;
            int chk = 1;
            while (cur)
            {
                int j = cur % 10;
                if (j == 3 || j == 4 || j == 7) 
                {
                    chk = 0;
                    break;
                }
                if (j == 2 || j == 5 || j == 6 || j == 9)
                {
                    d++;
                }
                cur /= 10;
            }
            if (chk && d) res++;
        }
        return res;
    }
};