class Solution 
{
public:
    int cal(unordered_map<int, int>& um, int n, int c)
    {
        int idx = 1;
        int res = 0;
        while (c * idx <= n)
        {
            int m = c * idx++;
            if (um.find(m) != um.end()) continue;
            um[m] = 1;
            res += m;
        }
        return res;
    }
    int sumOfMultiples(int n) 
    {
        unordered_map<int, int> um;
        return cal(um, n, 3) + cal(um, n, 5) + cal(um, n, 7);
    }
};