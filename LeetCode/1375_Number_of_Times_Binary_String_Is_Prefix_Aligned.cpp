class Solution 
{
public:
    int numTimesAllBlue(vector<int>& flips) 
    {
        int res = 0, maxValue = 0;;
        for (int i = 1; i <= flips.size(); i++)
        {
            maxValue = max(maxValue, flips[i-1]);
            if (maxValue == i)
            {
                res++;
            }
        }
        return res;
    }
};