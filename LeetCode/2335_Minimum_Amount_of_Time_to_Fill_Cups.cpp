class Solution 
{
public:
    int fillCups(vector<int>& amount) 
    {
        int res = 0;
        int sum = 1;
        for (auto n : amount)
        {
            res = max(res, n);
            sum += n;
        }
        sum /= 2;
        return max(res, sum);
    }
};