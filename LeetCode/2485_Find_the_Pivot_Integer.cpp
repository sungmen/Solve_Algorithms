class Solution 
{
public:
    int pivotInteger(int n) 
    {
        vector<int> v(n + 1, 0);
        v[n] = n;
        int r = 1;
        for (int i = n - 1; i >= 1; i--)
        {
            v[i] = i + v[i + 1];
        }
        for (int i = 1; i <= n; i++)
        {
            if (r == v[i])
                return i;
            r += (i + 1);
        }
        return -1;
    }
};