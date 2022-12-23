class Solution 
{
public:
    int countOdds(int low, int high) 
    {
        int res = 0;
        res += (low % 2);
        res += (high % 2);
        int back = res / 2;
        return res += (((high - low) / 2) - back);
    }
};